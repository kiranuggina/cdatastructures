#include "list.h"

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
void removeduplicates(node_t *head)
{
  node_t *curr = head;
  if(curr == NULL) return; // do nothing if the list is empty.
  while(curr->next != NULL) {
    if(curr->val == curr->next->val) {
      node_t *temp = curr->next->next;
      free(curr->next);
      curr->next = temp;
    } else {
      curr = curr->next;  // only advance if no deletion.
    }
  }
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
node_t *removeduplicates2(node_t *head)
{
  node_t *dummy = (node_t *) malloc (sizeof(node_t));
  dummy->next = NULL;
  node_t *prev = dummy;
  while(head != NULL) {
    if(head->next != NULL  && head->val == head->next->val) {
      // skip the nodes whose values are equal to head.
      while(head->next != NULL && head->val == head->next->val) {
        head = head->next;
      }
      prev->next = head->next;
    } else {
      if(prev->next == NULL)
        prev->next = head;
      prev = prev->next;
    }
    head = head->next;
  }
  return dummy->next;
}
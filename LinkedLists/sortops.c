#include "list.h"

void insertsorted(node_t **head, int val)
{
  NEWNODE(node, val);
  if(*head == NULL || (*head)->val > val) {
    node->next = *head;
    *head = node;
  } else {
    node_t *curr = *head;
    while(curr->next!= NULL && val > curr->next->val)
    {
      curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
  }
  return;
}

void mergesort(node_t **headnode)
{
  node_t *head = *headnode;
  node_t *a, *b;

  //Base case -- lenght 0 or 1
  if(head == NULL || head->next == NULL) return;

  // split head into 'a' and 'b' sublists
  splitlistinto2(head, &a, &b);

  // recursively sort the sublists
  mergesort(&a);
  mergesort(&b);

  // merge the two sorted lists together.
  *headnode = merge_sorted_recursive(a,b);
}
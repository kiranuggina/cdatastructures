#include "list.h"

void middle_of_the_list(node_t *head)
{
  node_t *slow, *fast;
  if(head == NULL)
    return;
  else {
    slow = head;
    fast = head;
    while(fast != NULL) {
      fast = fast->next;
      if(fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    // slow is before the midpoint in the list.
    printf("middle item -> %d\n", slow->val);
    return;
  }
  return;
}

void nth_node_from_end(node_t *head, int pos)
{
  node_t *p1, *p2;
  if(head == NULL)
    return;
  printf("\nFinding %dth node : ", pos);
  p1 = head;
  p2 = head;
  // move the first pointer to n nodes.
  while(pos > 0 && p1 != NULL) {
    p1 = p1->next;
    pos--;
  }
  // move the second pointer till the first pointer reaches null (last node).
  while(p1 != NULL) {
    p2 = p2->next;
    p1 = p1->next;
  }

  // p2 is exactly at nth node if p1 reaches null.
  if(p2 && pos == 0)
    printf("%d\n", p2->val);
  else 
    printf("not found\n");
}

void detect_loop(node_t *head) {
  node_t *slow, *fast;
  if(head == NULL)
    return;
  slow = head;
  fast = head->next;
  while(fast != NULL && slow == fast) {
    fast = fast->next;
    if(fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  if(slow == fast)
    printf("\nloop detected\n");
  else
    printf("\nno loop\n");
}
#include "list.h"

/* iterative approach */
void reverse_iterative(node_t **head)
{
  node_t *p, *q, *r;
  if(*head == NULL)
    return;
  
  p = *head;
  q = p->next;
  p->next = NULL;

  while(q!=NULL) {
    r = q->next;
    q->next = p;
    p = q;
    q = r;
  }
  *head = p;
}

/* recursive approach */
node_t *reverse_recursive(node_t *head)
{
  if(head == NULL || head->next == NULL)
    return head;
  // reverse the list and put the first element at the end.
  node_t * result = reverse_recursive(head->next);
  if(head->next)
    head->next->next = head;

  // Tricky but require.
  head->next = NULL;

  // fix the head pointer.
  return result;
}

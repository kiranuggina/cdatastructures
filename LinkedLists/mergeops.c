#include "list.h"

/* Iterative model that joins two unsorted linked lists */
node_t *merge_unsorted(node_t *l1, node_t *l2)
{
  node_t *new = l1, *temp = l1, *prev;

  // return if both lists empty.
  if(l1==NULL && l2==NULL)
    return NULL;

  while(temp)
  {
    prev = temp;
    temp = temp->next;
  }

  // add list 2 to the end of l1.
  if(temp==NULL)
    prev->next = l2;

  return new;
}

/*  Iterative model that joins already sorted linked lists */
node_t *merge_sorted(node_t *head1, node_t *head2)
{
  node_t *l1 = head1, *l2 = head2, *newhead = NULL, *temp = NULL;

  if(l1==NULL) return l2;
  else if (l2==NULL) return l1;

  while(l1!=NULL && l2!=NULL) {
    if(l1->val < l2->val) {
      if(temp==NULL)
        temp = l1;
      else {
        temp->next = l1;
        temp = temp->next;
      }
      l1 = l1->next;
    } else if (l1->val > l2->val) {
      if(temp==NULL)
        temp = l2;
      else {
        temp->next = l2;
        temp = temp->next;
      }
      l2 = l2->next;
    } else {
      // Both are equal, arbitarily choose to add one of them or skip both.
      if(temp == NULL)
        temp = l1;
      else {
        temp->next = l1;
        temp = temp->next;
      }
      l1 = l1->next;
      l2 = l2->next;
    }

    // make sure the new head is set.
    if(newhead == NULL)
      newhead = temp;
  }

  if(l1==NULL && l2==NULL)
    return newhead;
  
  if(l1==NULL)
    temp->next = l2;
  else if (l2==NULL)
    temp->next = l1;

  return newhead;
}

/* recursive approach that joins two sorted lists */
node_t *merge_sorted_recursive(node_t *l1, node_t *l2)
{
  node_t * result = NULL;

  if(l1 == NULL)
    return l2;
  else if (l2 == NULL)
    return l1;
  
  if(l1->val <= l2->val)
  {
    result = l1;
    result->next = merge_sorted_recursive(l1->next, l2);
  } else {
    result = l2;
    result->next = merge_sorted_recursive(l1, l2->next);
  }

  return result;
}
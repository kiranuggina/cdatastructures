#include "list.h"

void splitlistinto2(node_t *source, node_t **frontref, node_t **backref) {
  node_t *fast;
  node_t *slow;

  if(source == NULL || source->next == NULL) {
    // length < 2 cases.
    *frontref = source;
    *backref = NULL;
  } else {
    slow = source;
    fast = source->next;
    // Advance fast two nodes, and advance slow one node.
    while(fast != NULL) {
      fast = fast->next;
      if(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    // slow is before the midpoint in the list, so split it in two at this point.
    *frontref = source;
    *backref = slow->next;
    slow->next = NULL;
  }
}
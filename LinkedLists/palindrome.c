#include "list.h"

bool ispalindrome(node_t **left, node_t *right)
{
  if(right == NULL)
    return true;

  bool isp = ispalindrome(left, right->next);
  if(isp == false)
    return false;
  
  bool isp1 = (right->val == (*left)->val);
  *left = (*left)->next;

  return isp1;
}
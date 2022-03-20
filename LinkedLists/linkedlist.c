#include "list.h"

void insertfront(node_t **head, int val)
{
  NEWNODE(node, val);
  if(*head == NULL) {
    *head = node;
  } else {
    node->next = *head;
    *head = node;
  }
}

void delete(node_t **head, int val)
{
  node_t *temp = *head, *prev;
  
  // If head node itself need to be deleted.
  if(temp!=NULL && temp->val == val) {
    printf("Deleting at head: %d\n", val);
    *head = temp->next;
    free(temp);
    return;
  }

  // search for the key in the list and track the prev node.
  while(temp!= NULL && temp->val != val) {
    prev = temp;
    temp = temp->next;
  }

  if(temp==NULL)
    return;
  
  printf("Deleting : %d\n", val);
  prev->next = temp->next;
  free(temp);
  

  return;
}

void displaylist(node_t *head)
{
  printf("\nItems in the list are: ");
  node_t * temp = head;
  while(temp) {
    printf("%d\t", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  printf("\nWelcome to linked and demonstrating its operations\n");

  //testdelete();
  //testsorted();
  //testunsorted();
  //testsorted_recursive();
  //testreverse();
  //testmiddle();
  //testmergesort();
  //testnthnode();
  //testremoveduplicates2();
  testpalindrome();

  return 0;
}
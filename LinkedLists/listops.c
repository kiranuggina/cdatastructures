#include "list.h"

void testsorted()
{
  printf("\nTesting sort and merge operations\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 10; i++)
    insertsorted(&l1, rand() % 10);
  displaylist(l1);

  node_t *l2 = NULL;
  for(int i = 1; i <= 20; i++)
    insertsorted(&l2, rand() % 20);
  displaylist(l2);

  removeduplicates(l1);
  removeduplicates(l2);
  
  printf("\nAfter merging two lists\n");
  node_t *l3 = merge_sorted(l1, l2);
  removeduplicates(l3);
  displaylist(l3);
}

void testunsorted()
{
  printf("\nTesting unsorted and merge operations\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 15; i++)
    insertsorted(&l1, rand() % 15);
  displaylist(l1);

  node_t *l2 = NULL;
  for(int i = 1; i<=10; i++)
    insertsorted(&l2, rand() % 25);
  displaylist(l2);

  removeduplicates(l1);
  removeduplicates(l2);

  node_t *l3 = merge_unsorted(l1,l2);
  removeduplicates(l3);
  displaylist(l3);
}

void testsorted_recursive()
{
  printf("\nTesting sort and merge operations using recursive\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 10; i++)
    insertsorted(&l1, rand() % 10);
  displaylist(l1);

  node_t *l2 = NULL;
  for(int i = 1; i <= 20; i++)
    insertsorted(&l2, rand() % 20);
  displaylist(l2);

  removeduplicates(l1);
  removeduplicates(l2);
  
  printf("\nAfter merging two lists using recursive\n");
  node_t *l3 = merge_sorted_recursive(l1, l2);
  removeduplicates(l3);
  displaylist(l3);
}

void testdelete()
{
  printf("\nLinked List to test the insertion and deletion...\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 10; i++)
    insertfront(&l1, i);

  displaylist(l1);
  
  // delete random
  delete(&l1, 2);
  // delete head node
  delete(&l1, 10);

  // delete last node.
  delete(&l1, 1);
  displaylist(l1);
}

void testreverse()
{
  printf("\nLinked List to test the reverse...\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 5; i++)
    insertfront(&l1, i);
  displaylist(l1);

  printf("\nAfter reversing using iterative..\n");
  reverse_iterative(&l1);
  displaylist(l1);
  node_t *l2 = reverse_recursive(l1);
  displaylist(l2);
}

void testmiddle()
{
  printf("\nLinked List to test the middle...\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 5; i++)
    insertfront(&l1, i);
  displaylist(l1);
  middle_of_the_list(l1);
}

void testmergesort()
{
  printf("\nLinked List to test the merge sort...\n");
  node_t *l1 = NULL;
  for(int i = 1; i <= 10; i++)
    insertfront(&l1, i);
  displaylist(l1);
  mergesort(&l1);
  displaylist(l1);
}

void testnthnode()
{
  node_t *l1 = NULL;
  for(int i = 1; i <= 10; i++)
    insertfront(&l1, i);
  displaylist(l1);
  nth_node_from_end(l1, rand() % 10);
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
void testremoveduplicates2(){
  node_t *l1 = NULL;

  for(int i = 1; i <= 10; i++)
    insertsorted(&l1, rand() % 10);
  
  displaylist(l1);

  node_t * l2 = removeduplicates2(l1);
  displaylist(l2);
}

void testpalindrome(){
  node_t *l1 = NULL;

  insertfront(&l1, 1);
  insertfront(&l1, 2);
  insertfront(&l1, 3);
  insertfront(&l1, 2);
  insertfront(&l1, 1);

  displaylist(l1);
  printf("\nis palindrome : %s\n", (ispalindrome(&l1, l1->next) == true)? "True" : "False" );

}
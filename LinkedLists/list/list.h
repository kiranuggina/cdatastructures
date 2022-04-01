#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NEWNODE(node, val) \
  node_t *node = (node_t*) malloc(sizeof(node_t)); \
  node->val = val;  \
  node->next = NULL; \

typedef struct node node_t;
typedef struct node {
  int val;
  node_t *next;
}node_t;


// sort functions.
void insertsorted(node_t **head, int val);
void mergesort(node_t **headnode);

// list test functions
void testdelete();
void testsorted();
void testunsorted();
void testsorted_recursive();
void testreverse();
void testmiddle();
void testmergesort();
void testnthnode();
void testremoveduplicates2();
void testpalindrome();

// default functions.
void insertfront(node_t **head, int val);
void deletenode(node_t **head, int val);
void displaylist(node_t *head);
void removeduplicates(node_t *head);
node_t *removeduplicates2(node_t *head);

// reverse funtions.
void reverse_iterative(node_t **head);
node_t *reverse_recursive(node_t *head);

// merge funtions.
node_t *merge_unsorted(node_t *l1, node_t *l2);
node_t *merge_sorted(node_t *head1, node_t *head2);
node_t *merge_sorted_recursive(node_t *l1, node_t *l2);

// split functions
void splitlistinto2(node_t *source, node_t **frontref, node_t **backref);

// find functions.
void middle_of_the_list(node_t *head);
void nth_node_from_end(node_t *head, int pos);

// palindrome
bool ispalindrome(node_t **left, node_t *right);
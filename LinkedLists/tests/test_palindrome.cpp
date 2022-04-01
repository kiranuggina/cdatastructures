#include <gtest/gtest.h>
#include <gmock/gmock.h>
extern "C"
{
#include "list.h"
}

TEST(test_list_palindrome, valid_palindrome)
{
    int arr[] = {1, 2, 3, 2, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    node_t *l1 = NULL;
    for(int i = 0; i < n; i++)
    {
        insertfront(&l1, arr[i]);
    }
    EXPECT_TRUE(l1 != NULL);
    EXPECT_TRUE(l1->next != NULL);
    EXPECT_TRUE(ispalindrome(&l1, l1->next));
}

TEST(test_list_palindrome, invalid_palindrome)
{
    int arr[] = {1, 2, 3, 2, 3};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    node_t *l1 = NULL;
    for(int i = 0; i < n; i++)
    {
        insertfront(&l1, arr[i]);
    }
    EXPECT_TRUE(l1 != NULL);
    EXPECT_TRUE(l1->next != NULL);
    EXPECT_FALSE(ispalindrome(&l1, l1->next));
}

TEST(test_list_palindrome, length_2_invalid)
{
    int arr[] = {1, 2};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    node_t *l1 = NULL;
    for(int i = 0; i < n; i++)
    {
        insertfront(&l1, arr[i]);
    }
    EXPECT_TRUE(l1 != NULL);
    EXPECT_TRUE(l1->next != NULL);
    EXPECT_FALSE(ispalindrome(&l1, l1->next));
}

TEST(test_list_palindrome, length_2_valid)
{
    int arr[] = {1, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    node_t *l1 = NULL;
    for(int i = 0; i < n; i++)
    {
        insertfront(&l1, arr[i]);
    }
    EXPECT_TRUE(l1 != NULL);
    EXPECT_TRUE(l1->next != NULL);
    EXPECT_TRUE(ispalindrome(&l1, l1->next));
}
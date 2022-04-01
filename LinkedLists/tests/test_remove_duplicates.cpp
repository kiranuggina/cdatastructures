#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <vector>
extern "C"
{
#include "list.h"
}

TEST(test_remove_duplicates, remove_random_duplicates)
{
    node_t *l1 = NULL;
    int arr[25] = {0};
    for(int i = 0; i < 25; i++)
    {
        arr[i] = rand() % 100;
        insertsorted(&l1, arr[i]);
        //std::cout << arr[i] << "=";
    }

    std::vector<int> vec(std::begin(arr), std::end(arr));
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    removeduplicates(l1);
    for(int i:vec)
    {
      //std::cout<< i << "=";
      ASSERT_TRUE(l1 != NULL);
      ASSERT_EQ(l1->val, i);
      l1 = l1->next;
    }
}

TEST(test_remove_duplicates, remove_duplicates2)
{
    node_t *list = NULL;
    std::vector<int> arr = {1,1,2,3,3,3,4,5,5,6,7,8,9};
    std::vector<int> result = {2,4,6,7,8,9};
    for(int i:arr)
      insertsorted(&list, i);

    node *list2 = removeduplicates2(list);
    for(int i:result)
    {
      //std::cout<< i << "=";
      ASSERT_TRUE(list2 != NULL);
      ASSERT_EQ(list2->val, i);
      list2 = list2->next;
    }

}
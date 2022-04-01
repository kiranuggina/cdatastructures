#include <gtest/gtest.h>
#include <gmock/gmock.h>
extern "C"
{
#include "sortingalgos.h"
}
TEST(test_heap_sort, sort_positive)
{
    int arr[] = {1, 5, 4, 6, 7, 9, 8, 10, 2, 3};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    EXPECT_THAT(arr, testing::ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
}

TEST(test_heap_sort, sort_negative)
{
    int arr[] = {-1, -5, -4, -6, -7, -9, -8, -10, -2, -3};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    EXPECT_THAT(arr, testing::ElementsAre(-10, -9, -8, -7, -6, -5, -4, -3, -2, -1));
}

TEST(test_heap_sort, sort_mixed)
{
    int arr[] = {-1, -5, 4, -6, -7, 9, -8, -10, 2, -3};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    EXPECT_THAT(arr, testing::ElementsAre(-10, -8, -7, -6, -5, -3, -1, 2, 4, 9));
}
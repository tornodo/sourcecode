/**
*@FileName alltest.h
*@Description 单元测试
*@Author 海盗
*@WeiXin tornodo
*@Date2020/6/10 010 12:48
*@Version V1.0
**/

#ifndef SOURCECODE_ALLTEST_H
#define SOURCECODE_ALLTEST_H
#include "maxHeap.h"
#include "bubsort.h"
#include "quicksort.h"

#include "gtest/gtest.h"

template <typename T>
void testPrintArr(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

TEST(maxHeap, maxHeapAllTest) {
    int arr[] = {1, 2, 3, 4, 5, 6, 10, 9, 8, 7, 0, 0, 0, 0, 0, 0};
    auto heap = new maxHeap<int>(arr, 10, 16);
    heap->printToString();
    int a = heap->removeMax();
    EXPECT_EQ(a, 10);
    heap->printToString();
    heap->insert(10);
    heap->printToString();
    heap->remove(5, a);
    EXPECT_EQ(a, 1);
    heap->printToString();
    delete heap;
}

TEST(bubble, bubbleTest) {
    int arr[] = {1, 2, 3, 4, 5, 6, 10, 9, 8, 7};
    printBubbleSort(arr, 10);
}

TEST(quicksort, quickSortTest) {
//    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr[] = { 23, 15, 26, 58, 46, 38, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort<int>(arr, 0, size - 1);
    testPrintArr(arr, size);
}

#endif //SOURCECODE_ALLTEST_H

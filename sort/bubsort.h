/**
*@FileName bubsort.h
*@Description 冒泡排序
*@Author 海盗
*@WeiXin tornodo
*@Date2020/6/10 010 12:11
*@Version V1.0
**/

#ifndef SOURCECODE_BUBSORT_H
#define SOURCECODE_BUBSORT_H

#include <iostream>

template <typename T>
void bubbleSort(T arr[], int n) {
    bool noSwap;
    for (int i = 0; i < n; i++) {
        noSwap = true;
        for (int j = n - 1; j > i; j--) {
            if (arr[j] > arr[j - 1]) {
                T tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                noSwap = false;
            }
        }
        if (noSwap) {
            return;
        }
    }
}

template <typename T>
void printBubbleSort(T arr[], int n) {
    if (n <= 0) {
        return;
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif //SOURCECODE_BUBSORT_H

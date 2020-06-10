/**
*@FileName quicksort.h
*@Description 快速排序
*@Author 海盗
*@WeiXin tornodo
*@Date2020/6/10 010 15:33
*@Version V1.0
**/

#ifndef SOURCECODE_QUICKSORT_H
#define SOURCECODE_QUICKSORT_H

#include "sort.h"

template <typename T>
static int partition(T arr[], int start, int end) {
    // 取出最右侧数据，此时最右侧属于一个空位
    T tmp = arr[end];
    // 之所以搞一份副本是为了保存原始的两个索引不变
    int s = start, e = end;
    // 下面所有的操作前提是前后两个索引（s和e）没有碰面
    while (s < e) {
        while(arr[s] <= tmp && s < e) {
            ++s;
        }
        if (s < e) {
            // 将大于tmp的数据放到右侧空位，此时arr[s]的位置属于空位
            arr[e] = arr[s];
            --e;
        }
        while(arr[e] > tmp && s < e) {
            --e;
        }
        if (s < e) {
            // 将小于tmp的数据放到左侧空位，此时arr[e]位置属于空位
            arr[s] = arr[e];
            ++s;
        }
    }
    // 回来吧亲，这是你的位置，考虑两种极端情况：
    // 1、全部小于tmp，那么此时s == e == end
    // 2、全部大于tmp，那么此时s == start
    arr[s] = tmp;
    return s;
}

template <typename T>
void quickSort(T arr[], int start, int end) {
    if (arr == nullptr || start < 0 || end <= 0 || end <= start) {
        return;
    }
    int half = halfIndex(start, end);
    // 将选择的数据跟数组最后一位交换
    swap(arr, half, end);
    int s = partition(arr, start, end);
    quickSort(arr, start, s - 1);
    quickSort(arr, s + 1, end);
}

#endif //SOURCECODE_QUICKSORT_H

/**
*@FileName sort.h
*@Description 公共头文件
*@Author 海盗
*@WeiXin tornodo
*@Date2020/6/10 010 17:05
*@Version V1.0
**/

#ifndef SOURCECODE_SORT_H
#define SOURCECODE_SORT_H

const int InvalidIndex = -1;

int halfIndex(int pos, int n) {
    if (n <= 0) {
        return 0;
    }
    return (pos + n) / 2;
}

template <typename T>
void swap(T arr[], int l, int r) {
    T tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

#endif //SOURCECODE_SORT_H

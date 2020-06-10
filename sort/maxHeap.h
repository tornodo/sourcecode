#pragma once
#include <iostream>
#include <exception>

template<typename T>
class maxHeap {
private:
    T* heapArray;
    int currentSize;
    int halfSize;
    int maxSize;

    const int NoLeftChild = -1;
    const int NoRightChild = -2;
    const int InvalidIndex = -3;

public:
    maxHeap(T* array, int num, int maxSize);
    virtual ~maxHeap();

    bool isLeaf(int pos) const;
    int leftChild(int pos) const;
    int rightChild(int pos) const;
    bool remove(int pos, T& node);
    bool insert(const T& node);
    T max();
    T removeMax();
    void printToString();

private:
    void buildHeap();
    void shiftDown(int pos);
    void shiftUp(int pos);
    int parent(int pos) const;

};


template<typename T>
maxHeap<T>::maxHeap(T* array, int num, int maxSize):
    heapArray(array), 
    currentSize(num),
    maxSize(maxSize) {
    if (array == nullptr || num < 0 || maxSize < 0) {
        throw std::runtime_error("maxheap construct: bad param");
    }
    halfSize = currentSize >> 1;
    buildHeap();
}
template<typename T>
maxHeap<T>::~maxHeap() {

}
template<typename T>
inline bool maxHeap<T>::isLeaf(int pos) const {
    return (pos >= halfSize) && (pos < currentSize);
}
template<typename T>
int maxHeap<T>::leftChild(int pos) const {
    int index = pos * 2 + 1;
    if (index >= currentSize) {
        return NoLeftChild;
    }
    return index;
}
template<typename T>
int maxHeap<T>::rightChild(int pos) const {
    int index = pos * 2 + 2;
    if (index >= currentSize) {
        return NoLeftChild;
    }
    return index;
}
template<typename T>
inline int maxHeap<T>::parent(int pos) const {
    return (pos - 1) / 2;
}
template<typename T>
bool maxHeap<T>::remove(int pos, T& node) {
    if (pos < 0 || pos >= currentSize || currentSize == 0) {
        return false;
    }
    node = heapArray[pos];
    shiftUp(pos);
    shiftDown(pos);
    heapArray[pos] = heapArray[--currentSize];
    return true;
}
template<typename T>
void maxHeap<T>::shiftDown(int pos) {
    int i = pos;
    const T tmp = heapArray[pos];
    int childIndex = 2 * pos + 1;

    for (; childIndex < currentSize;) {
        if (childIndex + 1 < currentSize && heapArray[childIndex] < heapArray[childIndex + 1]) {
            childIndex++;
        }
        if (tmp < heapArray[childIndex]) {
            heapArray[i] = heapArray[childIndex];
            i = childIndex;
            childIndex = childIndex * 2 + 1;
        } else {
            break;
        }

    }
    heapArray[i] = tmp;

}
template<typename T>
void maxHeap<T>::shiftUp(int pos) {
    int i = pos;
    T tmp = heapArray[pos];
    int parentIndex = parent(pos);

    while(parentIndex >= 0 && heapArray[parentIndex] < tmp) {
        heapArray[i] = heapArray[parentIndex];
        i = parentIndex;
        if (parentIndex == 0) {
            break;
        }
        parentIndex = parent(parentIndex);
    }
    heapArray[i] = tmp;
}
template<typename T>
bool maxHeap<T>::insert(const T& node) {
    if (currentSize == maxSize) {
        return false;
    }
    heapArray[currentSize] = node;
    shiftUp(currentSize);
    currentSize++;
    return true;
}
template<typename T>
inline T maxHeap<T>::max() {
    return heapArray[0];
}
template<typename T>
T maxHeap<T>::removeMax() {
    if (currentSize == 0) {
        throw std::runtime_error("array is empty");
    } else {
        T tmp = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        heapArray[currentSize - 1] = 0;
        currentSize--;
        shiftDown(0);
        return tmp;
    }
}

template<typename T>
void maxHeap<T>::buildHeap() {
    if (currentSize == 1) {
        return;
    }
    for (int i = halfSize - 1; i >=0; i--) {
        shiftDown(i);
    }
}

template<typename T>
void maxHeap<T>::printToString() {
    for (int i = 0; i < currentSize; i++) {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;
    int intent = 0;
    for (int i = 0, j = 0; i < maxSize; j = i + 1, i = (i + 1) * 2) {
        // 树的层
        for (; intent < j; intent++) {
            std::cout << "-";
        }
        intent = j;
        std::cout << " ";
        for (; j <= i && j < currentSize; j++) {
            std::cout << heapArray[j] << " ";
            if (j % 2 == 0) {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}
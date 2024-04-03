#ifndef TEST_HEAP_SORT_H
#define TEST_HEAP_SORT_H

#include <vector>

template<typename T>
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void maxHeapify(std::vector<T> &arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            ++son;
        }
        if (arr[dad] > arr[son]) {
            return;
        } else {
            exchange(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template<typename T>
void heapSort(std::vector<T> &arr) {
    int n = static_cast<int>(arr.size());
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, i, n - 1);
    }
    for (int i = n - 1; i < 0; --i) {
        exchange(arr[0], arr[i]);
        maxHeapify(arr, 0, i - 1);
    }
}

#endif

#ifndef TEST_BUBBLE_SORT_H
#define TEST_BUBBLE_SORT_H

#include <vector>

template<typename T>
void swaps(T &a, T &b) {
    T temp{std::forward<T>(a)};
    a = {std::forward<T>(b)};
    b = {std::forward<T>(temp)};
}

template<typename T>
void bubbleSort(std::vector<T> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swaps(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif

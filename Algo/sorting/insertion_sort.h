#ifndef TEST_INSERTION_SORT_H
#define TEST_INSERTION_SORT_H

#include <vector>

template<typename T>
void insertionSort(std::vector<T> &arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i) {
        T temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; --j) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

#endif

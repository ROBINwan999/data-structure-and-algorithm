#ifndef TEST_SELECTION_SORT_H
#define TEST_SELECTION_SORT_H

#include <vector>

template<typename T>
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void selectionSort(std::vector<T> &arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        exchange(arr[i], arr[min]);
    }
}

#endif

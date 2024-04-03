#ifndef TEST_QUICK_SORT_H
#define TEST_QUICK_SORT_H

#include <vector>

template<typename T>
int partition(std::vector<T> &arr, int low, int high) {
    T pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            --high;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

template<typename T>
void quickSort(std::vector<T> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

template<typename T>
void quickSort(std::vector<T> &arr) {
    quickSort(arr, 0, arr.size() - 1);
}

#endif

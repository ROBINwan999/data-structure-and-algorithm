#ifndef TEST_MERGE_SORT_H
#define TEST_MERGE_SORT_H

#include <vector>

template<typename T>
void merge(std::vector<T> &arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int index = 0;
    std::vector<T> temp(right - left);
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[index++] = arr[i++];
    }
    while (j <= right) {
        temp[index++] = arr[j++];
    }
    index = 0;
    while (left <= right) {
        arr[left++] = temp[index++];
    }
}

template<typename T>
void mergeSort(std::vector<T> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template<typename T>
void mergeSort(std::vector<T> &arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

#endif

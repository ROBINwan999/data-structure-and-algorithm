#ifndef TEST_BINARY_SEARCH_H
#define TEST_BINARY_SEARCH_H

#include <vector>

template<typename T>
int binarySearch(std::vector<T> &arr, const T &target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

#endif

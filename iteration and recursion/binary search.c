#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: if the range is invalid (element not found)
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2; // Find the middle element

    // If the target is found
    if (arr[mid] == target) {
        return mid;
    }

    // If the target is smaller than the mid element, search the left half
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }
    // If the target is larger than the mid element, search the right half
    else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sample sorted array
    int target = 10;                // Element to search for
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

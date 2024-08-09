#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @class quickSort
 * @brief Class for implementing the quicksort algorithm.
 */
class quickSort {
private:
    /**
     * @brief Function to print the array.
     * @param arr The array to be printed.
     * @param n The size of the array.
     */
    void printArr(int* arr, int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Partition function for quicksort.
     * @param arr The array to be partitioned.
     * @param s The starting index of the partition.
     * @param e The ending index of the partition.
     * @return The index of the pivot element after partitioning.
     */
    int partition(int* arr, int s, int e) {
        int pivot = arr[s];
        int count = 0;

        for (int i = s + 1; i <= e; i++) {
            if (arr[i] <= pivot) {
                count++;
            }
        }

        // Place pivot at correct index position
        int pivotIndex = s + count;
        swap(arr[s], arr[pivotIndex]);

        // Making left of pivot less than pivot, right of pivot greater than pivot
        int i = s, j = e;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }
        return pivotIndex;
    }

    /**
     * @brief Helper function for quicksort.
     * @param arr The array to be sorted.
     * @param s The starting index of the array.
     * @param e The ending index of the array.
     */
    void quickSortHelper(int* arr, int s, int e) {
        if (s >= e) {
            return;
        }

        // Partition
        int p = partition(arr, s, e);

        // Sort left part
        quickSortHelper(arr, s, p - 1);

        // Sort right part
        quickSortHelper(arr, p + 1, e);
    }

public:
    /**
     * @brief Public function to initiate sorting.
     * @param arr The array to be sorted.
     * @param n The size of the array.
     */
    void sort(int* arr, int n) {
        int s = 0;
        int e = n - 1;
        quickSortHelper(arr, s, e);
        printArr(arr, n);
    }
};

int main() {
    quickSort obj;

    // Test case: Array with no elements
    int arr1[0] = {};
    obj.sort(arr1, 0);

    // Test case: Array with one element
    int arr2[1] = {5};
    obj.sort(arr2, 1);

    // Test case: Array with already sorted elements
    int arr3[5] = {1, 2, 3, 4, 5};
    obj.sort(arr3, 5);

    // Test case: Array with reverse sorted elements
    int arr4[5] = {5, 4, 3, 2, 1};
    obj.sort(arr4, 5);

    // Test case: Array with negative elements
    int arr5[6] = {-5, -2, -1, -4, -3, -2};
    obj.sort(arr5, 6);
}

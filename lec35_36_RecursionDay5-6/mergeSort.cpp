#include <iostream>
using namespace std;

/**
 * @class mergeSort
 * @brief Class that implements the merge sort algorithm.
 */
class mergeSort {
private:
    /**
     * @brief Prints the elements of an array.
     * @param arr The array to be printed.
     * @param n The size of the array.
     */
    void printArr(int* arr,int n) {
        for (int i=0; i<n;  i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }

    /**
     * @brief Merges two sorted subarrays into one sorted array.
     * @param arr The array containing the subarrays.
     * @param s The starting index of the first subarray.
     * @param e The ending index of the second subarray.
     */
    void merge (int* arr, int s, int e) {
        int mid = s+(e-s)/2;
        int len1 = mid-s+1;
        int len2 = e-mid;

        int* first = new int[len1];
        int* second = new int[len2];
        int mainArrayIndex = s;
        for (int i=0; i<len1; i++) {
            first[i] = arr[mainArrayIndex++];
        }
        mainArrayIndex = mid+1;
        for (int i=0; i<len2; i++) {
            second[i] = arr[mainArrayIndex++];
        }
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;
        while (index1 < len1 && index2 < len2) {
            if (first[index1] < second[index2]) {
                arr[mainArrayIndex++] = first[index1++];
            } 
            else if (second[index2] < first[index1]) {
                arr[mainArrayIndex++] = second[index2++];
            }
            else {
                arr[mainArrayIndex++] = first[index1++];
                arr[mainArrayIndex++] = second[index2++];
            }
        }
        while (index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];
        }
        while (index2 < len2) {
            arr[mainArrayIndex++] = second[index2++];
        }

        delete[] first;
        delete[] second;
    }

    /**
     * @brief Recursive helper function for merge sort.
     * @param arr The array to be sorted.
     * @param s The starting index of the subarray to be sorted.
     * @param e The ending index of the subarray to be sorted.
     */
    void mergeSortHelper(int* arr, int s, int e) {
        if (s>=e) {
            return;
        }
        int mid = s+(e-s)/2;
        // sort left part
        mergeSortHelper(arr, s, mid);
        //sort right part
        mergeSortHelper(arr, mid+1, e);
        // merge
        merge(arr,s,e);
    }

public:
    /**
     * @brief Sorts an array using merge sort algorithm.
     * @param arr The array to be sorted.
     * @param n The size of the array.
     */
    void sort(int* arr,int n){
        int s = 0;
        int e = n-1;
        mergeSortHelper(arr, s, e);
        printArr(arr,n);
    }
};

int main() {
    mergeSort obj;

    // Test case 1: Empty array
    int arr1[0] = {};
    obj.sort(arr1, 0);

    // Test case 2: Array with one element
    int arr2[1] = {5};
    obj.sort(arr2, 1);

    // Test case 3: Array with already sorted elements
    int arr3[5] = {1, 2, 3, 4, 5};
    obj.sort(arr3, 5);

    // Test case 4: Array with reverse sorted elements
    int arr4[5] = {5, 4, 3, 2, 1};
    obj.sort(arr4, 5);

    // Test case 5: Array with duplicate elements
    int arr5[8] = {3, 2, 1, 4, 3, 2, 5, 1};
    obj.sort(arr5, 8);

    return 0;
}
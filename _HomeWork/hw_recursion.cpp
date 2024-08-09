#include <iostream>
#include <vector>
using namespace std;

/**
 * - TODO: practice all the binary search problems using recursion
 * 
 * - [x]first position last position
 * - [x]Peak Index in a Mountain Array
 * - [ ]aggressive cows
 * - [ ]book allocation
 * - [ ]pivot
 * - [ ]search in rotated array
 * - [ ]sqrt
 * - [ ]selection sort
 * - [ ]insertion sort
 * - [ ]subset/subsequence (using bits manipulation)
 * 
 */
int firstOcc(int arr[], int start, int end, int key) {
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        // Check if it's the first occurrence
        if (mid == 0 || arr[mid - 1] != key) {
            return mid;
        }
        // Search in the left half
        return firstOcc(arr, start, mid - 1, key);
    } else if (key < arr[mid]) {
        return firstOcc(arr, start, mid - 1, key);
    } else {
        return firstOcc(arr, mid + 1, end, key);
    }
}
int lastOcc(int arr[], int start, int end, int key) {
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        // Check if it's the last occurrence
        if (mid == end || arr[mid + 1] != key) {
            return mid;
        }
        // Search in the right half
        return lastOcc(arr, mid + 1, end, key);
    } else if (key < arr[mid]) {
        return lastOcc(arr, start, mid - 1, key);
    } else {
        return lastOcc(arr, mid + 1, end, key);
    }
}
int peakIndexInMountainArray(vector<int>& arr, int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] < arr[mid + 1]) {
        return peakIndexInMountainArray(arr, mid + 1, end);
    } else {
        return peakIndexInMountainArray(arr, start, mid);
    }
}
int main() {
    // // first position last position
    // int arr[9] = {1,3,3,3,4,4,5,5,6};
    // cout << firstOcc(arr,0,8,1) << endl; // 0
    // cout << firstOcc(arr,0,8,3) << endl; // 1
    // cout << firstOcc(arr,0,8,4) << endl; // 4
    // cout << firstOcc(arr,0,8,5) << endl; // 6
    // cout << firstOcc(arr,0,8,6) << endl; // 8
    // cout << firstOcc(arr,0,8,0) << endl; // -1
    // cout <<endl;
    // cout << lastOcc(arr,0,8,1) << endl; // 0
    // cout << lastOcc(arr,0,8,3) << endl; // 3
    // cout << lastOcc(arr,0,8,4) << endl; // 5
    // cout << lastOcc(arr,0,8,5) << endl; // 7
    // cout << lastOcc(arr,0,8,6) << endl; // 8
    // cout << lastOcc(arr,0,8,0) << endl; // -1

    // Peak Index in a Mountain Array
    // Test case 1: Mountain with peak in the middle
    vector<int> mountain1 = {1, 3, 5, 7, 6, 4, 2};
    cout << "Peak index: " << peakIndexInMountainArray(mountain1, 0, mountain1.size() - 1) << endl; // Expected output: 3
    // Test case 2: Mountain with peak at the beginning
    vector<int> mountain2 = {10, 8, 6, 4, 2, 1};
    cout << "Peak index: " << peakIndexInMountainArray(mountain2, 0, mountain2.size() - 1) << endl; // Expected output: 0
    // Test case 3: Mountain with peak at the end
    vector<int> mountain3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Peak index: " << peakIndexInMountainArray(mountain3, 0, mountain3.size() - 1) << endl; // Expected output: 9

    return 0;
}
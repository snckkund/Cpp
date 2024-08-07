#include <iostream>
#include <vector>
using namespace std;
/* @Code360: Binary Search */
int binarySearch(const vector<int>& arr, int left, int right, int key) {
    // Base case
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    // If key is greater, ignore the left half
    if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, right, key);
    }
    // If key is smaller, ignore the right half
    return binarySearch(arr, left, mid - 1, key);
}

int search(const vector<int>& nums, int target) {
    int n = nums.size();
    return binarySearch(nums, 0, n - 1, target);
}

int main() {
    vector<int> arr = {5, 9, 14, 15, 16, 22, 23, 24, 28, 29, 34};

    // Test cases
    cout << search(arr, 9) << endl;  // Output: 1
    cout << search(arr, 15) << endl; // Output: 3
    cout << search(arr, 100) << endl; // Output: -1

    return 0;
}

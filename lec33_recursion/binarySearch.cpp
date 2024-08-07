#include <iostream>
using namespace std;

bool binarySearch(int arr[], int n, int key) {
    if (n == 0) {
        return false;
    }

    int mid = (n - 1) / 2;

    if (arr[mid] == key) {
        return true;
    } else if (arr[mid] < key) {
        // Search in the right half
        return binarySearch(arr + mid + 1, n - mid - 1, key);
    } else {
        // Search in the left half
        return binarySearch(arr, mid, key);
    }
}

int main() {
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    // Test cases
    cout << (binarySearch(arr, 7, 3) ? "found" : "not found") << endl;
    cout << (binarySearch(arr, 7, 8) ? "found" : "not found") << endl;
    cout << (binarySearch(arr, 7, 1) ? "found" : "not found") << endl;
    cout << (binarySearch(arr, 7, 7) ? "found" : "not found") << endl;
    cout << (binarySearch(arr, 7, 5) ? "found" : "not found") << endl;
    cout << (binarySearch(arr, 7, 0) ? "found" : "not found") << endl;

    return 0;
}
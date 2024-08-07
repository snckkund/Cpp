#include <iostream>
#include <climits>
using namespace std;

/**
 * Checks if an array is sorted in non-decreasing order.
 * 
 * @param arr The array to be checked.
 * @param n The number of elements in the array.
 * @return True if the array is sorted, false otherwise.
 */
bool isSorted(int arr[], int n) {
    if (n == 0 || n== 1) {
        return true;
    }
    if (arr[0] > arr[1]) {
        return false;
    }
    else {
        return isSorted(arr+1,n-1); 
    }
}

int main() {
    // code here
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << (isSorted(arr,n)==1 ? "Sorted" : "Not-sorted") << endl;

    delete[] arr;

    return 0;
}
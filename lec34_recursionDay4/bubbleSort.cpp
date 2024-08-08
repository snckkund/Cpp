#include <iostream>
using namespace std;

void sortArray (int arr[], int n) {
    if (n==0 || n==1) {
        return;
    } 
    for (int i=0; i<n-1; i++) {
        if (arr[i]>arr[i+1]) {
            swap(arr[i],arr[i+1]);
        }
        sortArray(arr,n-1);
    }
}

int main() {
    // Test case 1: Empty array
    int arr1[] = {};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sortArray(arr1, n1);
    cout << "Sorted array: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Test case 2: Array with one element
    int arr2[] = {5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sortArray(arr2, n2);
    cout << "Sorted array: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Test case 3: Array with multiple elements
    int arr3[] = {10, 5, 8, 3, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    sortArray(arr3, n3);
    cout << "Sorted array: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
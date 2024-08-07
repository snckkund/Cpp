#include <iostream>
using namespace std;

/**
 * Calculates the sum of elements in an integer array.
 *
 * @param arr The integer array.
 * @param n The number of elements in the array.
 * @return The sum of elements in the array.
 */
int getsum(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else if (n==1) {
        return arr[0];
    } 
 
    return arr[0] + getsum(arr+1,n-1);
}

int main() {
    // code here
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "sum of all elements: " << getsum(arr,n) << endl;

    delete[] arr;
    return 0;
}
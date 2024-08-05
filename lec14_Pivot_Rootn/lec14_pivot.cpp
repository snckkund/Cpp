// Search In Rotated Sorted Array {code360}

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>& arr, int n) {
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while (start < end) {
        if (arr[mid] >= arr[0]) {
            start = mid+1;
        } else {
            end=mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int binarySearch(vector<int>& arr, int s, int e, int k) {
    int start = s;
    int end = e;
    int mid = start + (end-start)/2;
    while (start <= end) {
        if (arr[mid]==k) {
            return mid;
        } else if (arr[mid] <= k) {
            start = mid+1;
        } else {
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getPivot(arr,n);
    if (arr[pivot] <= k && k <= arr[n-1]) { // bs on seconf line
        return binarySearch(arr, pivot, n-1, k);
    } else { // bs on first line
        return binarySearch(arr, 0, pivot-1, k);
    }
}

int main() {
    // code here
    vector<int> A = {11,13,5,8,9,10};
    cout << "Search In Rotated Sorted Array. index: " << search(A, 6, 5);

    return 0;
}
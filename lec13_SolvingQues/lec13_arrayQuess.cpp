#include <iostream>
#include <vector>
using namespace std;

// @Code360: First and Last Position of an Element In Sorted Array
int firstOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end) {
        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end) {
        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

// @Leetcode {# 852). Peak Index in a Mountain Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start) / 2;
        while (start < end) {
            if (arr[mid] < arr[mid+1]) {
                start = mid + 1;
            }
            else {
                end=mid;
            }
            mid = start + (end - start) / 2;
        }
        return mid;
    }
};

int main() {
    // // code360
    // int even[6] = {2,3,5,5,9,11};
    // int odd[7] = {0,6,12,12,12,14,18};
    // cout << "First occurence at index: " << firstOcc(even,6,5) << endl;
    // cout << "last occurence at index: " << lastOcc(even,6,5) << endl;
    // cout << endl;
    // cout << "First occurence at index: " << firstOcc(odd,7,12) << endl;
    // cout << "last occurence at index: " << lastOcc(odd,7,12) << endl;

    // leetcode
    vector<int> mountain = {0,10,5,32,54,89,99,23,20,2};
    Solution obj;
    cout << "peak of the mountain is at index: " << obj.peakIndexInMountainArray(mountain);

    return 0;
}
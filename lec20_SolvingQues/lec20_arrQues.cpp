#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

// @Code360: {reverse an array}
void reverseArray(vector<int> &arr , int m) {
    // Write your code here       	
    int s = m+1;
    int e = arr.size()-1;
    while (s<=e) {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

class Solution {
public:
    // @Leetcode {# 88. Merge Sorted Array}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> newArr;
        for (int i=0; i<m+n; i++) {
            if (i<m) {
                newArr.push_back(nums1[i]);
            }
            else {
                newArr.push_back(nums2[n+m-i-1]);
            }
        }
        sort(newArr.begin(), newArr.end());
        nums1=newArr;
        printVector(nums1);
    }

    // @Leetcode {# 283. Move Zeroes}
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for (int j=0; j<nums.size(); j++) {
            if (nums[j]!=0) {
                swap(nums[j],nums[i]);
                i++;
            }
        }
        printVector(nums);
    }
};

int main() {

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // int m = 3;
    // reverseArray(v,m); // reverse an array
    // printVector(v);

    Solution obj;

    // vector<int> v1 = {1,2,3,0,0,0};
    // int m = 3;
    // vector<int> v2 = {2,5,6};
    // int n = 3;
    // obj.merge(v1,m,v2,n); // merge two arrays

    // vector<int> v3 = {0,1,0,3,12};
    // obj.moveZeroes(v3); // move zeros

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int>& arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

// @Code360: sum of two arrays
vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    vector<int> sum;

    while (i >= 0 || j >= 0 || carry) {
        int sumDigit = carry;

        if (i >= 0) {
            sumDigit += a[i];
            i--;
        }

        if (j >= 0) {
            sumDigit += b[j];
            j--;
        }

        carry = sumDigit / 10;
        sumDigit %= 10;

        sum.push_back(sumDigit);
    }

    reverse(sum.begin(), sum.end());
    return sum;
}

class Solution {
public:
    // @LeetCode {# 189. rotate array}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i=0; i<n; i++) {
            temp[(i+k)%n] = nums[i];
        }
        nums=temp;
        printVec(nums,n);
    }

    // @LeetCode  {# 1752. Check if Array Is Sorted and Rotated}
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i=1; i<n; i++) {
            if (nums[i-1]>nums[i]) {
                count++;
            }
        }
        if (nums[n-1]>nums[0]) {
            count++;
        }
        return count <= 1;
    }
};

int main() {

    Solution obj;

    // vector<int> v = {1,2,3,4,5,6,7};
    // int k = 3;
    // obj.rotate(v,k); // rotate an array by k

    // vector<int> v1 = {3,4,5,1,2};
    // vector<int> v2 = {2,1,3,4};
    // cout << "sorted rotated array? v1 -> " << obj.check(v1) << endl; // rotate an array by k
    // cout << "sorted rotated array? v2 -> " << obj.check(v2) << endl;

    vector<int> a = {1, 2, 3};
    int n = 3;
    vector<int> b = {9, 9};
    int m = 2;
    cout << "a + b -> ";
    vector<int> sum = findArraySum(a,n,b,m); // add two arrays
    printVec(sum,sum.size());

    return 0;
}
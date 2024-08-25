#include <iostream>
#include <mylibs/utilsc++.h>
using namespace std;

// @Gfg: Reverse sub array

class Solution {
  public:
    vector<int> reverseSubArray(vector<int> &arr, int l, int r) {
        // code here
        l--;
        r--;
        while(l<r) {
            int temp = arr[r];
            arr[r--] = arr[l];
            arr[l++] = temp;
        }

        return arr;
    }
};

// void reverse(int arr[], int n) {

//     for(int i=0; i < n/2; i++) {
//         swap(arr[i],arr[n-i-1]);
//     }
// }

int main() {

    MyUtils obj;

    // int arr[6] = {1,2,3,4,5,6};
    // obj.printArray(arr);
    // reverse(arr,6);
    // obj.printArray(arr);

    vector<int> arr = {1,2,3,4,5,6,7};
    obj.printVector(arr);
    
    Solution sol;
    arr = sol.reverseSubArray(arr, 2, 4);
    obj.printVector(arr);
    
    return 0;
}
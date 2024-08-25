#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// @Gfg: Min and Max in Array

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        long long min = INT64_MAX;
        long long max = INT64_MIN;

        // min
        for (int i=0; i<arr.size(); i++) {
            if(arr[i] < min) {
                min = arr[i];
            }
        }
        // max
        for (int i=0; i<arr.size(); i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
        }

        return make_pair(min,max);
    }
};

// int getMin(int arr[], int n) {
//     int min = INT_MAX;

//     for(int i=0; i<n; i++) {
//         if(arr[i] < min) {
//             min = arr[i];
//         }
//     }

//     return min;
// }
// int getMax(int arr[], int n) {
//     int max = INT_MIN;

//     for(int i=0; i<n; i++) {
//         if(arr[i] > max) {
//             max = arr[i];
//         }
//     }

//     return max;
// }
int main() {
    
    // int arr[5] = {3,5,8,2,9};
    // cout << "min: " << getMin(arr,5) << endl;
    // cout << "max: " << getMax(arr,5) << endl;

    vector<long long int> arr = {3, 2, 1, 56, 10000, 167};

    Solution sol;
    cout << "min: " << sol.getMinMax(arr).first << endl;
    cout << "max: " << sol.getMinMax(arr).second << endl;
    
    return 0;
}
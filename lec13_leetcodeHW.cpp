// leetcode {# 724}. Find Pivot Index {h/w}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int lhs=0;
            int rhs=0;
            for (int j=i-1; j>=0; j--) {
                lhs=lhs+nums[j];
            }
            for (int k=n-1; k>i; k--) {
                rhs=rhs+nums[k];
            }
            if (lhs==rhs) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    // code here
    vector<int> p = {1,2,3,-4,6};
    Solution obj;
    cout << "pivot index at: " << obj.pivotIndex(p);

    return 0;
}
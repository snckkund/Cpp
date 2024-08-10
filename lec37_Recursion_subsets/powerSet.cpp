#include <iostream>
#include <vector>
using namespace std;
// @Leetcode: {78. subsets}
class powerSet
{
private:
    void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
        // base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(nums, output, index+1, ans);
        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
public:
    void print (vector<vector<int>>& v) {
        for (vector<int> i:v) {
            cout << "{";
            for (int j:i) {
                cout << j << (j!=i[i.size()-1]?",":"");
            }cout << "}" << endl;
        }cout << endl;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main() {
    powerSet obj;
    
    // Test Case 1: Empty input
    vector<int> nums1;
    vector<vector<int>> result1 = obj.subsets(nums1);
    obj.print(result1);
    // Expected output: {}

    // Test Case 2: Single element input
    vector<int> nums2 = {1};
    vector<vector<int>> result2 = obj.subsets(nums2);
    obj.print(result2);
    // Expected output: {}, {1}

    // Test Case 3: Multiple element input
    vector<int> nums3 = {1, 2, 3};
    vector<vector<int>> result3 = obj.subsets(nums3);
    obj.print(result3);
    // Expected output: {}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}

    return 0;
}
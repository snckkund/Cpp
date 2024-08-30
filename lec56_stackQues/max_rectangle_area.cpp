#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @Leetcode: 84. Largest Rectangle In Histogram

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        while(--n >= 0) {
            int curr = arr[n];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[n] = s.top();
            s.push(n);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = -1;
        for (int i=0; i<n; i++) {
            int l = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
};

int main() {
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "largest rectangle area: " << obj.largestRectangleArea(heights);
    
    return 0;
}
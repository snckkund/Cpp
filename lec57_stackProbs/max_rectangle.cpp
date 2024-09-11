#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @Gfg: Max rectangle

class Solution{
  private:
    vector<int> nextSmallerElement(int* arr, int n) {
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
    
    vector<int> prevSmallerElement(int* arr, int n) {
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
    
    int largestRectangleArea(int* heights, int n) {

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
    
  public:
    int maxArea(int M[][4], int n, int m) {
        // compute area for first row
        int area = largestRectangleArea(M[0],m);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                // row update: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                
                else
                    M[i][j] = 0;
                
            }
            
            // entire row is updated now
            area = max(area, largestRectangleArea(M[i],m));
        }
        return area;
    }
};

int main() {
    
    Solution obj;

    int M[][4] = { {0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0} }; 
    
    cout << "largest rectangle area is: " << obj.maxArea(M,4,4);

    return 0;
}
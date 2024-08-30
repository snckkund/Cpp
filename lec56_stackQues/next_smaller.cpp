#include <iostream>
#include <vector>
#include <stack>
#include <mylibs/utilsc++.h>
using namespace std;

// @Code360: Next Smaller Element

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    while(--n >= 0) {
        int curr = arr[n];
        while (s.top() >= curr) {
            s.pop();
        }
        // ans is top of stack
        ans[n] = s.top();
        s.push(curr);
    }

    return ans;

}

int main() {
    MyUtils obj;
    
    vector<int> v = {2,1,4,3};
    vector<int> ans = nextSmallerElement(v, 4);

    obj.printVector(ans);
    
    return 0;
}
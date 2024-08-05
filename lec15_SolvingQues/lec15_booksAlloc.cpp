// code360-  Allocate Books

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    for (int i=0; i<n; i++) {
        if (pageSum+arr[i] <= mid) {
            pageSum+=arr[i];
            
        } else {
            studentCount++;
            if ( studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
	// Write your code here.
    int start = 0;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum+=arr[i];
    }
    int end = sum;
    int mid = start + (end-start)/2;
    int  ans = -1;
    if (m>n) {
        return ans;
    }
    while (start <= end) {
        if (isPossible(arr,n,m,mid)) {
            ans=mid;
            end=mid-1;
        } else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main() {
    // code here
    vector<int> a= {2,8,8,4,5};
    cout << findPages(a,5,6) << endl;

    vector<int> b= {10,20,30,40};
    cout << findPages(b,4,2);
    return 0;
}
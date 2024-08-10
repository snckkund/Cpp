// @Leetcode: {#69 Sqrt(x)}
#include <iostream>
#include <vector>
using namespace std;

long long int binarySearch(int n) {
    int start = 0;
    int end = n;
    long long int mid = start + (end-start)/2;
    long long int  ans = -1;
    while (start <= end) {
        long long int sq = mid*mid;
        if (sq==n) {
            return mid;
        } else if (sq < n) {
            ans = mid;
            start = mid+1;
        } else {
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int floorSqrt(int n) {
    return binarySearch(n);
}

// more precision
double morePrecision(int n, int precision, int tempSol) {
    double fact = 1;
    double ans = tempSol;
    for (int i=0; i<precision; i++) {
        fact /= 10;
        for (double j=ans; j*j<n; j+=fact) {
            ans=j;
        }
    }
    return ans;
}

int main() {
    // code here
    int n;
    cout << "enter a number: ";
    cin >> n;
    int tempSol = floorSqrt(n);
    cout << "floor square root: " << tempSol << endl;
    // more precision
    cout << "3 precision square root: " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}

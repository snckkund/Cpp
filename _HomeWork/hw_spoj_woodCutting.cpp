// [!link](https://www.spoj.com/problems/EKO/) 
// @Homework EKO (SPOJ)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkHeight(vector<int>& arr, long long mid, long long m) {
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mid) {
            sum += arr[i] - mid;
            if (sum >= m) {
                return true;
            }
        }
    }
    return sum >= m;
}

// Function to find the maximum height of the sawblade
int maxHeight(int n, long long m, vector<int>& arr) {
    long long start = 0;
    long long end = *max_element(arr.begin(), arr.end());
    long long mid;
    int ans = 0;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (checkHeight(arr, mid, m)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    cout << maxHeight(n, m, tree) << endl;
    return 0;
}

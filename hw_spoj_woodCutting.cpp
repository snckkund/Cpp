// [!link](https://www.spoj.com/problems/EKO/)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkHeight(vector<int>& arr, int mid, int m) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= mid) {
            sum += arr[i] - mid;
        }
    }
    return sum >= m;
}

int maxHeight(int n, int m, vector<int>& arr) {
    int start = 0;
    int end = *max_element(arr.begin(), arr.end());
    int mid;
    int ans = -1;
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
    int n, m;
    cin >> n >> m;
    vector<int> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    cout << maxHeight(n, m, tree) << endl;

    return 0;
}
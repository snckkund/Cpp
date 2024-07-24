#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isPossible (vector<int> &stalls, int k, int mid) {
    int countCows = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            countCows++;
            if (countCows == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = 0;

    for (int i = 0; i < stalls.size(); i++) {
        maxi = max(maxi,stalls[i]);
    }

    int e = maxi;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (isPossible (stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    // code here
    vector<int> stalls= {4,2,1,3,6};
    cout << aggressiveCows (stalls, 2) << endl;
    
    return 0;
}
// https://www.naukri.com/code360/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&count=25&search=&sort_entity=order&sort_order=ASC&page=1
//  @Homework: cooking ninja
// @Code360
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

bool checkTime(const vector<int> &rank, int T, int m) {
    int totalDishes = 0;
    for (int r : rank) {
        int time = 0;
        int k = 1;
        while (time + k * r <= T) {
            time += k * r;
            totalDishes++;
            if (totalDishes >= m) return true;
            k++;
        }
    }
    return totalDishes >= m;
}

int minCookTime(const vector<int> &rank, int m) {
    
    int s = *min_element(rank.begin(), rank.end());
    int e = *max_element(rank.begin(), rank.end()) * (m * (m + 1)) / 2;
    int ans = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (checkTime(rank, mid, m)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n,m;
    vector<int> rank;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int r;
        cin >> r;
        rank.push_back(r);
    }
    cout << minCookTime(rank,m) << endl;

    return 0;
}
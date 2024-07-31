// https://www.naukri.com/code360/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&count=25&search=&sort_entity=order&sort_order=ASC&page=1

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

bool checkTime(vector<int> arr, int mid, int m) {

}

int minCookTime(vector<int> &rank, int m) {
    // Write your code here
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
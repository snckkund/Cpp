// @Code360: print series
#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int>& v) {
    for (int i:v) {
        cout << i << " ";
    } cout << endl;
}

void generateSeries(int n, int k, vector<int>& ans, bool subtract) { 
    ans.push_back(n);

    if (subtract && n > 0) {
        generateSeries(n - k, k, ans, true);
    } else if (subtract && n <= 0) {
        generateSeries(n + k, k, ans, false);
    }

    if (!subtract && n < ans[0]) {
        generateSeries(n + k, k, ans, false);
    }
}

vector<int> printSeries(int n, int k) {
    vector<int> ans;
    generateSeries(n, k, ans, true);
    return ans;
}

int main() {
    // code here
    int T,n,k;
    vector<int> v;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        v = printSeries(n,k);
        printVec(v);
    }
    return 0;
}
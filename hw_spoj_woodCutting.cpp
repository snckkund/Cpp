// https://www.spoj.com/problems/EKO/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>& arr) {
    for (auto i:arr) {
        cout << i << " ";
    } cout << endl;
}

int main() {
    // code here
    vector<int> v = {65,66,67,68,69};
    print(v);

    return 0;
}
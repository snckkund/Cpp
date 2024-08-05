#include <iostream>
#include <queue>
using namespace std;

int main() {

    // max heap
    priority_queue<int> maxh;
    maxh.push(1);
    maxh.push(3);
    maxh.push(2);
    maxh.push(0);

    int n = maxh.size();
    for (int i=0; i<n; i++) {
        cout << maxh.top() << " ";
        maxh.pop();
    } cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minh;
    minh.push(5);
    minh.push(1);
    minh.push(0);
    minh.push(4);
    minh.push(3);

    int m = minh.size();
    for (int i=0; i<m; i++) {
        cout << minh.top() << " ";
        minh.pop();
    } cout << endl;

    cout << "empty? : " << minh.empty() << endl;

    // cout << "size -> " << maxh.size();


    return 0;
}
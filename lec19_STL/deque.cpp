#include <iostream>
#include <deque>

using namespace std;

int main() {
    // code here
    deque <int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_front(3);

    cout << "d -> ";
    for (int i=0; i<d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    // d.pop_back();

    // cout << "d -> ";
    // for (int i=0; i<d.size(); i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    // d.pop_front();

    // cout << "d -> ";
    // for (int i=0; i<d.size(); i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    cout << "first -> " << d.front() << endl;
    cout << "last -> " << d.back() << endl;
    cout << "element at index 1 -> " << d.at(1) << endl;
    cout << "empty? -> " << d.empty() << endl;

    cout << "before erase -> " << d.size() << " | ";
    d.erase(d.begin(), d.begin()+1);
    cout << "after erase -> " << d.size() << endl;

    return 0;
}
#include <iostream>
#include <set>
using namespace std;

int main() {
    // code here
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(0);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(6);
    s.insert(0);
    s.insert(0);

    for (auto i:s) {
        cout << i << " ";
    } cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for (auto i:s) {
        cout << i << " ";
    } cout << endl;

    cout << "1 is present? : " << s.count(1) << endl;
    cout << "0 is present? : " << s.count(0) << endl;

    set<int>::iterator itr = s.find(5);
    cout << "value present at itr -> " << *itr << endl;

    for (auto it=itr; it!=s.end(); it++) {
        cout << *it << " ";
    } cout << endl;

    return 0;
}
#include <iostream>
#include <list>

using namespace std;

int main() {
    // code here
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_front(3);

    list<int> n(l); // list "l" copied to list "n"

    list<int> m(5,100); // all 5 elements become 100
    cout << "m -> ";
    for (int i:m) {
        cout << i << " ";
    }
    cout << endl;

    cout << "l -> ";
    for (int i:l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "before erase -> " << l.size() << " | ";
    l.erase(l.begin());
    cout << "after erase -> " << l.size() << endl;

    return 0;
}
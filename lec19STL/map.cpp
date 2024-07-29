#include <iostream>
#include <map>
using namespace std;

int main() {
    // code here
    map<int,string> m;

    m[1] = "a";
    m[13] = "z";
    m[2] = "b";

    m.insert({5,"k"});

    cout << "before erase: " << endl;
    for (auto i:m) {
        cout << i.first << " : " << i.second << endl;
    } cout << endl;

    cout << "finding 13 -> " << m.count(13) << endl;
    cout << "finding 4 -> " << m.count(4) << endl  << endl;

    m.erase(1);
    cout << "after erase: " << endl;
    for (auto i:m) {
        cout << i.first << " : " << i.second << endl;
    } cout << endl;

    auto it = m.find(5);
    for (auto i = it; i!=m.end(); i++) {
        cout << (*i).first << endl;
    }

    return 0;
}
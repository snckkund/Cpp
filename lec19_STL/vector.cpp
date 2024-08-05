#include <iostream>
#include <vector>

using namespace std;

int main() {
    // code here
    vector <int> v;

    cout << "vec -> ";
    vector <int> vec(5,1); // creates a vector "vec" of size 5 and assigns "1" to each index. default: 0
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << " | ";

    cout << "v1 -> ";
    vector <int> v1(vec); // copies all elements of vector "vec" to v1
    for (int i=0; i<v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "capacity -> " << v.capacity() << endl; // capacity() : memory assigned to the array

    v.push_back(1);
    cout << "capacity -> " << v.capacity() << endl;

    v.push_back(2);
    cout << "capacity -> " << v.capacity() << endl;

    v.push_back(3);
    cout << "capacity -> " << v.capacity() << endl;
    cout << "size -> " << v.size() << endl; // size() : number of elements

    cout << "element at index 2 -> " << v.at(2) << endl;
    cout << "first element -> " << v.front() << " | ";
    cout << "last element -> " << v.back() << endl;

    cout << "before pop -> " ;
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }

    v.pop_back();

    cout << " | ";
    cout << "after pop -> " ;
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "before clear -> " << v.size() << " | ";
    v.clear(); // size becomes 0, not capacity
    cout << "after clear -> " << v.size() << endl;

    // // first iterator: v.begin();
    // // last iterator: v.end();



    return 0;
}
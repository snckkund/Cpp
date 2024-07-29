#include <iostream>
#include <array>

using namespace std;

int main() {
    // code here
    int basic[3] = {1,2,3};

    array<int,4> a = {1,2,3,4};

    int size = a.size();
    for (int i=0; i<size; i++) {
        cout << a[i] << " ";
    }

    cout << "element at index 2 -> " << a.at(2) << endl;
    cout << "empty? -> " << a.empty() << endl;
    cout << "first element of the array -> " << a.front() << endl;
    cout << "last element of the array -> " << a.back() << endl;

    return 0;
}
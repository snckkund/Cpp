#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
    for (int i=0; i<size; i++) {
        if (arr[i]==key) {
            return true;
        }
    }
    return 0;
}

int main() {
    int arrayfirst[10]={7,8,3,9,0,-1,11,-3,6,-9};
    int key;
    cout << "enter the key: ";
    cin >> key;
    bool search = linearSearch(arrayfirst,10,key);
    if (search) {
        cout << "key present in array";
    }
    else {
        cout << "key absent in array";
    }
    return 0;
}
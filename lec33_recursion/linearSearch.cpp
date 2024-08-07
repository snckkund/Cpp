#include <iostream>
using namespace std;

bool search(int arr[], int n, int key) {
    if (n==0) {
        return false;
    } else if (arr[0]==key) {
        return true;
    }
    return search(arr+1,n-1,key);
}

int main() {
    // code here
    int n,key;
    cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> key;
    cout << (search(arr,n,key)==1 ? "found" : "not found") << endl;

    delete[] arr;
    return 0;
}
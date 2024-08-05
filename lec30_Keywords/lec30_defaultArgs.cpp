#include <iostream>
using namespace std;

void print(int arr[], int n, int start=0) { // start=0 is a default argument
    for (int i=start; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    print(arr,size,2);
    print(arr,size);

    return 0;
}
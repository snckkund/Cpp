#include <iostream>
using namespace std;
void printP(int * p) { // passing pointer in a function (pass by reference)

    cout << p << " - " << *p << endl;
}

void update(int * p) {

    // p=p+1;
    // cout << "inside p - " << p << endl;
    *p = *p+1;
}

int getSum (int arr[], int n) { // int getSum(int *arr, int n) {passes pointer to array}
    // cout << endl << "size: " << sizeof(arr) << endl;
    int sum=0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // int value = 5;
    // int * p = &value;
    // printP(p);
    // cout << "p before - " << *p << endl;
    // update(p);
    // cout << "p after - " << *p << endl;

    int arr[6] = {1,2,3,4,5,8};
    cout << "sum is: " << getSum(arr+3, 3) << endl;

    return 0;
}
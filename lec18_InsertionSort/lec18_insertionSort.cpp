#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

void insertionSort(int n, vector<int> &arr){
    for (int i=1; i<n; i++) {
        int temp = arr[i];
        int j=i-1;
        for (; j>=0; j--) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main() {
    // code here
    vector<int> a= {6,2,8,4,10};

    insertionSort(5,a);
    printVector(a);
    return 0;
}
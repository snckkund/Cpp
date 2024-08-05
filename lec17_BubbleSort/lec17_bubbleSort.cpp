#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    bool swapped = false;
    for (int i=0; i<n; i++) { // 0 1 2 3
        for (int j=0; j<n-i-1; j++) { // 5 4 3 2
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main() {
    // code here
    vector<int> a= {6,2,8,4,10};

    bubbleSort(a,5);
    printVector(a);


    return 0;
}
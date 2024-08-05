#include <bits/stdc++.h> 
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

void selectionSort(vector<int>& arr, int n) {   
    // Write your code here.
    for (int i = 0; i < n-1; i++) {
        int minInd = i;
        for (int j = i+1; j<n; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        swap(arr[minInd],arr[i]);
    }
}

int main() {
    // code here
    vector<int> a= {6,2,8,4,10};

    selectionSort(a,5);
    printVector(a);
    return 0;
}
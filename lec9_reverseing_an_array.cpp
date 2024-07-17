#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int size) {
    int start=0;
    int end=size-1;
    for (int i=0; i<size; i++) {
        if (end>start) {
            int swap = arr[end];
            arr[end]=arr[start];
            arr[start]=swap;
            start++;
            end--;
        }
    }
    printArray(arr, size);
}

int main() {

    int arr[6]={3,5,6,9,0,-1};
    int brr[5]={-2,4,9,0,7};

    reverseArray(arr,6);
    reverseArray(brr,5);

    return 0;
}
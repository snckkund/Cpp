#include <iostream>
#include <climits>
using namespace std;

// printing array using function
void printArray(int arr[], int size) {
    for (int i=0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMax(int arr[], int size) {
    int max = INT_MIN;
    for (int i=0; i<size; i++) {
        if (arr[i] > max) {
            max=arr[i];
        }
    }
    return max;
}

int getMin(int arr[], int size) {
    int min = INT_MAX;
    for (int i=0; i<size; i++) {
        if (arr[i] < min) {
            min=arr[i];
        }
    }
    return min;
}

void updateArray(int arr[], int size) {
    cout << "inside the update fuction" << endl;

    // updating array
    arr[0]=120;
    printArray(arr,size);

    cout << "going back to main function" << endl;
}

// sum of all elements in the array {h/w}
int sumof(int arr[], int size) {
    int sum=0;
    for (int i=0; i<size; i++) {
        sum=sum+arr[i];
    }
    return sum;
}

int main() {
    // // initialising an array
    // int arr[3] = {5,7,11};
    // cout << "value at index 2 is: "<< arr[2];

    // int first[15] = {2,7}; // {2,7,0,0,0,0,0,0,0,0,0,0,0,0,0}
    // int n = 15;
    // cout << "printing array" << endl;
    // for (int i=0; i<n; i++) {
    //     cout << first[i] << " ";
    // }

    // int second[10] = {0}; // assigns all indices with 0
    // int n = 15;
    // cout << "printing array" << endl;
    // for (int i=0; i<n; i++) {
    //     second[i]=1; // assigns all indices with 1
    //     cout << second[i] << " ";
    // }

    // // printing array using function
    // int third[5] = {1,4};
    // int n = 5;
    // printArray(third,n);

    // // sizeof array
    // int fourth[8] = {0};
    // int k = sizeof(fourth)/sizeof(int);
    // cout << "size of fourth is: " << k ;

    // // max min of an array
    // cout << "size: ";
    // int size;
    // cin >> size;
    // int fifth[100];
    // cout << "enter elements: ";
    // for (int i=0; i<size; i++) {
    //     cin >> fifth[i];
    // }
    // cout << "Maximum of array: " << getMax(fifth,size) << endl;
    // cout << "Minimum of array: " << getMin(fifth,size) << endl;

    // // updating the array
    // int array[3]={100,200,300};
    // updateArray(array,3); // updating the array inside a fucntion changes value in the main too
    // printArray(array,3);  // because incase of array as function parameter, address of the first element of the array is passed. 
    
    // // sum of all the elements
    // int array2[10]={4,-6,-5,3,7,8,4,-36,25,10};
    // cout << "sum of all the elements of the array is: " << sumof(array2,10);

    return 0;
}
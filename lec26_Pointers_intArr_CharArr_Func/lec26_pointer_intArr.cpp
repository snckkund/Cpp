#include <iostream>
using namespace std;

int main() {
    // working of pointers in case of arrays
    // int arr[5] = {1,0,5,7,6};
    //
    // cout << arr << endl; // 0x61fefc (address of first element of arr)
    // cout << &arr << endl; // 0x61fefc
    // cout << &arr[0] << endl; // 0x61fefc
    //
    // int *p = arr;
    // cout << p << endl; // 0x61fefc
    // cout << &p << endl; // 0x61fef8 (pointer address)
    //
    // cout << *p << endl; // 1    
    // cout << *arr << endl; // 1
    // cout << *arr+1 << endl; // 2
    // cout << (*arr)+1 << endl; // 2
    // cout << *(arr+1) << endl; // 0
    //
    // cout << arr[0] << endl; // 1
    // cout << 0[arr] << endl; // 1
    // cout << p[0] << endl; // 1
    //
    // cout << *p+1 << endl; // 2
    // cout << (*p)+1 << endl; // 2
    // cout << p+1 << endl; // 0x61ff00 (0x61fefc + 0x000004)
    //
    // // ERROR - // arr = arr+1
    //
    // p = (arr+1);
    // cout << p << endl; // 0x61ff00
    // cout << p[0] << endl; // 0
    // cout << *p << endl; // 0
    //
    // // arr[i] == i[arr] ==  *(arr+i)

    // int arr1 [10];
    // int *ptr1 = arr1;
    // cout << sizeof(arr1) << endl; // 40
    // cout << sizeof(*arr1) << endl; // 4 (size of integer)
    // cout << sizeof(*ptr1) << endl; // 4 (size of integer)
    // cout << sizeof(ptr1) << endl; // 4 (size of pointer)
    // cout << sizeof(&ptr1) << endl; // 4 (size of address stored in pointer)
    //
    // double arr2 [10];
    // double *ptr2 = arr2;
    // cout << sizeof(arr2) << endl; // 80
    // cout << sizeof(*arr2) << endl; // 8 (size of double)
    // cout << sizeof(*ptr2) << endl; // 8 (size of double)
    // cout << sizeof(ptr2) << endl; // 4 (size of pointer)
    // cout << sizeof(&ptr2) << endl; // 4 (size of address stored in pointer)


    return 0;
}
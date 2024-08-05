#include <iostream>
using namespace std;
/*
 * It creates a dynamic 2D array in dynamic memory, takes input for the array,
 * outputs the array, frees up the heap memory, and outputs a message indicating
 * that the heap memory has been cleared.
 */
int main() {
    /* 
    int arr[5][5]; // 2D array in static memory 
    */

    // // # Creating a dynamic 2D array in dynamic allocation of memory
    int row,col;
    cout << "enter `row`, `column` number : " ;
    cin >> row >> col;
    
    /* creating a 2D array in dynamic memory */
    int** arr = new int*[row]; // creating array of `row` that stores pointers
    for (int i=0; i<row; i++) {
        * (arr+i) = new int[col]; // creating arrays of `col` in heap corresponding to each pointer in `**arr`
    }
    /* 2D array is created */

    // taking input for array
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }
    // output
    cout << endl;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }

    /* #################( freeing-up heap )################# */
    for (int i=0; i<row; i++) { 
        delete[] arr[i]; // Delete each row
    }
    delete[] arr; // Delete the array of pointers

    // output (after clearing heap)
    cout << endl << " < - - heap memory cleared - - > " << endl;

    return 0;
}
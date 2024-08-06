/*
  @Homework: creating jaggered array in dynamic memory 
*/
#include <iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    // Allocate memory for an array that stores the size of each row
    int* colSize = new int[row];

    // Taking input of variable column sizes
    cout << "Enter " << row << " column sizes: ";
    for (int i = 0; i < row; i++) {
        cin >> colSize[i]; 
    }

    // Allocate memory for the jagged array
    int** jaggedArray = new int*[row];

    // Creating a 2D array in heap memory with different column lengths
    for (int i = 0; i < row; i++) {
        jaggedArray[i] = new int[colSize[i]]; // Allocate each row with its column size
    }

    // Taking input for array elements
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < row; i++) {
        int col = colSize[i];
        for (int j = 0; j < col; j++) {
            cin >> jaggedArray[i][j];
        }
    }

    // Output the jagged array
    cout << "Jagged array:" << endl;
    for (int i = 0; i < row; i++) {
        int col = colSize[i];
        cout << "[" << col << "] -> ";
        for (int j = 0; j < col; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting the allocated memory
    delete[] colSize; // Delete the array that stores column sizes
    for (int i = 0; i < row; i++) {
        delete[] jaggedArray[i]; // Delete each row
    }
    delete[] jaggedArray; // Delete the array of pointers

    // Output message after clearing heap memory
    cout << endl << " < - - heap memory cleared - - > " << endl;

    return 0;
}

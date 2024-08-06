#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool isPresent(int arr[][4], int row, int col, int target) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (arr[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;
}

void sumRows(int arr[][3], int row, int col) {
    for (int i=0; i<row; i++) {
        int sum = 0;
        for (int j=0; j<col; j++) {
            sum+=arr[i][j];
        } cout << sum << endl;
    }
}

void sumCols(int arr[][3], int row, int col) {
    for (int j=0; j<col; j++) {
        int sum = 0;
        for (int i=0; i<row; i++) {
            sum+=arr[i][j];
        } cout << sum << " ";
    }cout << endl;
}

int largestRowSum(int arr[][3], int row, int col) {
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int i=0; i<row; i++) {
        int sum = 0;
        for (int j=0; j<col; j++) {
            sum+=arr[i][j];
        } 
        
        if (sum > maxi) {
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << "maximum row sum it at row: " << rowIndex << endl;

    return maxi;
}

// printing vector<int>
void printVec(vector<int> arr) {
    int n = arr.size();
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// @@Code360: {wave printing}
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> wave;

    for (int col=0; col<mCols; col++) {
        if (col%2==0) {
            for (int row=0; row<nRows; row++) {
                wave.push_back(arr[row][col]);
            }
        }
        else {
            for (int row=nRows-1; row>=0; row--) {
                wave.push_back(arr[row][col]);
            }
        }
    }

    return wave;
}

// @LeetCode {# 54. Spiral Matrix}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};

    int nrows = matrix.size();
    int mcols = matrix[0].size();

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = nrows - 1;
    int endingCol = mcols - 1;
    int count = 0;

    vector<int> spiral;

    while (count < nrows * mcols) {
        // Traverse from left to right
        for (int index = startingCol; index <= endingCol && count < nrows * mcols; index++) {
            spiral.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // Traverse downwards
        for (int index = startingRow; index <= endingRow && count < nrows * mcols; index++) {
            spiral.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // Traverse from right to left
        for (int index = endingCol; index >= startingCol && count < nrows * mcols; index--) {
            spiral.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // Traverse upwards
        for (int index = endingRow; index >= startingRow && count < nrows * mcols; index--) {
            spiral.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return spiral;
}

// print vector<vector<int>>
void printVecVec(vector<vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << arr[i][j] << " ";

        } cout << endl;
    }
}
// @LeetCode {# 48. Rotate Image}
void rotate90(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int row = 0; row < n / 2; row++) {
        for (int col = row; col < n - row - 1; col++) {
            // Swap the top-left and top-right cells in the current group
            swap(matrix[row][col], matrix[col][n - 1 - row]);
            // Swap the top-left and bottom-right cells in the current group
            swap(matrix[row][col], matrix[n - 1 - row][n - 1 - col]);
            // Swap the top-left and bottom-left cells in the current group
            swap(matrix[row][col], matrix[n - 1 - col][row]);
        }
    }
}

void rotate180(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // swapping columns
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n/2; col++) {
            swap(matrix[row][col], matrix[row][n-1-col]);
        }
    }
    // swapping rows
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n/2; row++) {
            swap(matrix[row][col], matrix[n-1-row][col]);
        }
    }
}

// using binary search in a matrix - leetcode {# 74. Search a 2D Matrix I}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nrows = matrix.size();
    int mcols = matrix[0].size();

    int s = 0;
    int e = nrows*mcols - 1;

    while (s<=e) {
        int mid = s + (e-s)/2;
        int element = matrix[mid/mcols][mid%mcols];
        
        if (target == element) {
            return true;
        }
        else if (element < target) {
            s = mid+1;
            
        }
        else {
            e = mid-1;
        }
    }
    return false;
}

// @LeetCode {# 240. Search a 2D Matrix II}
bool searchMatrixII(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int nrows = matrix.size();
    int mcols = matrix[0].size();

    int rowIndex = 0;
    int colIndex = mcols - 1;

    while (rowIndex < nrows && colIndex >= 0) {
        int element = matrix[rowIndex][colIndex];

        if (target == element) {
            return true;

        } else if (element < target) {
            rowIndex++;

        } else {
            colIndex--;

        }
    }
    return false;
}

int main() {

    // hard input
    // int d2arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // int d2arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};

    // // taking input for 2d array (row-wise)
    // int d2arr[3][4];
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<4; j++) {
    //         cin >> d2arr[i][j];
    //     }
    // }

    // // taking input for 2d array (column-wise)
    // int d2arr[3][4];
    // for (int j=0; j<4; j++) {
    //     for (int i=0; i<3; i++) {
    //         cin >> d2arr[i][j];
    //     }
    // }

    // // output 2d array
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<4; j++) {
    //         cout << d2arr[i][j] << " ";
    //     } cout << endl;
    // }

    // // search element
    // cout << "enter the a number to search: ";
    // int target;
    // cin >> target;
    // if (isPresent(d2arr,3,4,target)) {
    //     cout << "Found!!" << endl;
    // } else {
    //     cout << "Not found!!" << endl;
    // }

    // // finding number of rows and cols
    // int d2arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    // cout << "Number of rows: " << sizeof(d2arr) / sizeof(d2arr[0]) << endl;
    // cout << "Number of columns: " << sizeof(d2arr[0]) / sizeof(d2arr[0][0]) << endl;


    // int d2arr[3][3] = { {3,4,11},
    //                     {2,12,1},
    //                     {7,8,7} };
    // // sum of each row
    // cout << "sum of rows: " << endl;
    // sumRows(d2arr,3,3);
    //
    // // sum of each col
    // cout << "sum of columns: " << endl;
    // sumCols(d2arr,3,3);
    //
    // cout << "maximum sum: " << largestRowSum(d2arr,3,3) << endl;


    // code 360
    // vector<vector<int>> mat1 = {{3,4,11},
    //                             {2,12,1},
    //                             {7,8,7}};
    //
    // vector<vector<int>> mat2 = {{1,11,111,1111},
    //                             {2,22,222,2222},
    //                             {3,33,333,3333},
    //                             {4,44,444,4444}};

    // cout << "wave 1 -> ";
    // vector<int> v1 = wavePrint(arr1,3,3);
    // printVec(v1);
    // 
    // cout << "wave 2 -> ";
    // vector<int> v2 = wavePrint(arr2,4,4);
    // printVec(v2);

    // cout << "spiral 1 -> ";
    // vector<int> v1 = spiralOrder(mat1);
    // printVec(v1);
    //
    // cout << "spiral 2 -> ";
    // vector<int> v2 = spiralOrder(mat2);
    // printVec(v2);

    // cout << "=======| 90 degree right rotated matrix |=======" << endl;
    // rotate90(mat2);
    // printVecVec(mat2);
    //
    // cout << "=======| 180 degree rotated matrix |=======" << endl;
    // rotate180(mat2);
    // printVecVec(mat2);

    // vector<vector<int>> matrix1 = { {1,3,5,7},
    //                                 {10,11,16,20},
    //                                 {23,30,34,60}  };
    // cout << "enter a number: ";
    // int k;
    // cin >> k;
    // if (searchMatrix(matrix1,k)) {
    //     cout << "present!!" << endl;
    // }
    // else {
    //     cout << "Not present!!" << endl;
    // }
    //
    vector<vector<int>> matrix2 = { {1,4,7,11,15},
                                    {2,5,8,12,19},
                                    {3,6,9,16,22},
                                    {10,13,14,17,24},
                                    {18,21,23,26,30} };
    cout << "enter a number: ";
    int k;
    cin >> k;
    if (searchMatrixII(matrix2,k)) {
        cout << "present!!" << endl;
    }
    else {
        cout << "Not present!!" << endl;
    }

    return 0;
}
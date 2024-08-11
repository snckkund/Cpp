#include <iostream>
#include <mylibs/utilsc++.h>
using namespace std;
/**
 * checking my local libs
 */
int main() {

    // 1D Array
    int arr1D[] = {1, 2, 3, 4, 5};
    double arr1DD[] = {1.1, 2.2, 3.3};
    string arr1DS[] = {"apple", "banana", "cherry"};
    MyUtils::printArray(arr1D);
    MyUtils::printArray(arr1DD);
    MyUtils::printArray(arr1DS);

    // 2D Array
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    double arr2DD[2][2] = {{1.1, 2.2}, {3.3, 4.4}};
    string arr2DS[2][2] = {{"apple", "banana"}, {"cherry", "date"}};
    MyUtils::print2DArray(arr2D);
    MyUtils::print2DArray(arr2DD);
    MyUtils::print2DArray(arr2DS);

    // 1D Vector
    vector<int> vi = {1, 2, 3, 4, 5};
    vector<double> vd = {1.1, 2.2, 3.3, 4.4};
    vector<string> vs = {"apple", "banana", "cherry"};
    MyUtils::printVector(vi);
    MyUtils::printVector(vd);
    MyUtils::printVector(vs);

    // 2D Vector
    vector<vector<int>> vvi = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<double>> vvd = {{1.1, 2.2}, {3.3, 4.4}};
    vector<vector<string>> vvs = {{"apple", "banana"}, {"cherry", "date"}};
    MyUtils::print2DVector(vvi);
    MyUtils::print2DVector(vvd);
    MyUtils::print2DVector(vvs);

    // Matrix
    vector<vector<int>> intMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<double>> doubleMatrix = {
        {1.1, 2.2, 3.3},
        {4.4, 5.5, 6.6},
        {7.7, 8.8, 9.9}
    };
    vector<vector<char>> charMatrix = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };
    MyUtils::printMatrix(intMatrix);
    MyUtils::printMatrix(doubleMatrix);
    MyUtils::printMatrix(charMatrix);

    return 0;
}

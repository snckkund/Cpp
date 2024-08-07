#include <iostream>
using namespace std;
// @Code360: Count Ways To Reach The N-th Stairs {using recursion} </TLE>
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if (nStairs<0) {
        return 0;
    } else if (nStairs==0) {
        return 1;
    } else {
        return countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
    }

}
int main() {
    // code here
    int T;
    cin >> T;
    int* arr = new int[T];
    for (int i=0; i<T; i++) {
        cin >> arr[i];
    } 
    cout << endl;
    for (int i=0; i<T; i++) {
        cout << countDistinctWays(arr[i]) << endl;
    }
    delete[] arr;
    return 0;
}
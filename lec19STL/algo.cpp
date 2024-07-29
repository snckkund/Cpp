#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // code here
    vector <int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "finding 5 using bs: " << binary_search(v.begin(), v.end(), 5) << endl;

    cout << "finding 6 using bs: " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "lower bound: " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    cout << "uper bound: " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    int a=3;
    int b=5;
    cout << "max: " << max(a,b) << endl;
    cout << "min: " << min(a,b) << endl;

    swap (a,b);
    cout << "a: " << a << endl << "b: " << b << endl;

    string abcd = "abcd";
    cout << "abcd (before reverse): " << abcd << endl;
    reverse(abcd.begin(), abcd.end());
    cout << "abcd (after reverse): " << abcd << endl;

    rotate(v.begin(), v.begin()+1, v.end());
    cout << "after rotate -> " ;
    for (int i:v) {
        cout << i << " ";
    } cout << endl;

    sort(v.begin(), v.end());
    cout << "after sort -> " ;

    for (int i:v) {
        cout << i << " ";
    } cout << endl;

    return 0;
}
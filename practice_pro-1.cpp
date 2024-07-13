// prime no using for loop
// GfG, 1<=n<=10^6

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // code here
    std::cout << "Enter a number: ";
    int n;
    cin >> n;
    string ans = "No";
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i==0) {
            ans = "No";
            break;
        } else if (n%i!=0) {
            ans = "Yes";
        }
    }
    if (n== 2 || n==3) {
        ans="Yes";
    }
    std::cout << ans;
    
    return 0;
}
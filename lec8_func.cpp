#include <iostream>
using namespace std;

// power (num1,num2) // - num1,num2 > 0
int powerOf(int num1, int num2) {
    int ans=1;
    for (int i=0; i<num2; i++) {
        ans=ans*num1;
    }
    return ans;
}

// isEven (x) // - n>=1
bool isEven(int x) {
    if (x&1)
        return 0;
    return 1;
}

// factorial(n) // - n>=0
int factorial (int n) {
    int fac=1;
    for (int i=1; i <= n; i++) {
        fac=fac*i;
    }
    return fac;
}

// nCr(n,r) // - n>=r>=0
int nCr(int n, int r) {
    int ans = factorial(n)/(factorial(n-r) * factorial(r)) ;
    return ans;
}

// printCounting(n) // - n>0
void printCounting(int n) {
    cout << "counting till " << n << endl;
    for (int i=1; i<=n; i++) {
        cout << i << endl;
    }
}

// isPrime(x) // - x>1
bool isprime(int x) {
    int prime=false;
    for (int i=2; i<x; i++) {
        if (x%i==0) {
            prime=false;
            break;
        }
        prime=true;
    }
    if (x==2) {
        prime=true;
    }
    return prime;
}

// AP() // - a+rn {h/w}

// set bits counter in a,b. i.e a=2=0b10, b=3=0b11 --> o/p = 3 {h/w}

// nth fibonacci number {h/w}

int main() {
    // // powerOf
    // cout << "enter a,b: ";
    // int a,b;
    // cin >> a >> b;
    // cout << "powerOf(" << a << "," << b << ") = "<< powerOf(a,b) << endl;

    // // isEven
    // cout << "enter a number: ";
    // int a;
    // cin >> a;
    // cout << isEven(a) << endl;

    // // factorial
    // cout << "enter a number to find its factorial: ";
    // int f;
    // cin >> f;
    // cout << factorial(f) << endl;

    // // nCr
    // cout << "enter n,r of nCr: ";
    // int n,r;
    // cin >> n >> r;
    // cout << "nCr(" << n << r << ")=" << nCr(n,r) << endl;

    // // printCounting
    // cout << "enter a number: ";
    // int a;
    // cin >> a;
    // printCounting(a);

    // // isPrime
    // cout << "enter a number: ";
    // int a;
    // cin >> a;
    // cout << "isPrime() returns " << isprime(a);

    return 0;
}
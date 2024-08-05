#include <iostream>
#include <bitset>
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

// AP() // - a+r*n {h/w}
float apCal(float a, float r, float n) {
    float ans = a+r*n;
    return ans;
}

int d2b(int decimal) {
    string binary="";
    for (; decimal!=0; decimal=decimal/2) {
        binary=to_string(decimal%2)+binary;
    }
    int bin=stoi(binary);
    return bin;
}

// set bits counter in a,b. i.e a=2=0b10, b=3=0b11 --> o/p = 3 {h/w}
int bitsCount(int a, int b) {
    a=d2b(a);
    b=d2b(b);
    int c_a=0;
    int c_b=0;
    for (; a!=0; a/=10) {
        if (a%10==0) {
            continue;
        } else if (a%10==1) {
            c_a++;
        }
    }
    for (; b!=0; b/=10) {
        if (b%10==0) {
            continue;
        } else if (b%10==1) {
            c_b++;
        }
    }
    cout << "set bits in a: "<< c_a << "\n" << "set bits in b: " << c_b << endl;
    return c_a+c_b;

}

// nth fibonacci number {h/w}
int fibo(int n) {
    if (n == 1) {
        return 1;
    }
    int a = 0;
    int b = 1;
    int sum;
    for (int i = 2; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}

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

    // // apCal
    // cout << "enter a,r,n: ";
    // float a,r,n;
    // cin >> a >> r >> n;
    // cout << "apCal() returns: " << apCal(a,r,n);

    // // decimal to binary
    // cout << "enter a number: ";
    // int d;
    // cin >> d;
    // cout << "decimal of " << d << " : " << d2b(d);

    // // bits count
    // cout << "enter a,b: ";
    // int a,b;
    // cin >> a >> b;
    // cout << "total: " << bitsCount(a,b);

    // nth fibonacci number
    cout << fibo(9);

    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if (n<=1) return false;
    for (int i=2; i<n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

// leetcode {# 204. count primes} - Sieve of Eratosthenes - O(n*log(log(n)))
int countPrimes(int n) {
    if (n < 2) return 0;
    int count = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i]) count++;
    }
    return count;
}
// GCD Naive approach - O(min(a, b))
int GCDnaive(int a, int b) {
    if (a == 0 && b == 0) {return 0;}
    int ans = 1;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            ans = i;
        }
    }
    return ans;
}
// GCD Euclidean Algorithm -  O(min(a, b))
int GCDeuI(int a, int b) {
    if (a==0) return b;
    if (b==0) return a;
    while (a!=b) {
        if (a>b) {a-=b;}
        else {b-=a;}
    }
    return a;
}
// GCD Euclidean Algorithm - O(log min(a, b))
int GCDeuII(int a,int b){
   if (b ==0){return a;} 
   else {return GCDeuII(b, a%b);}
}

// code 360 {Modular Exponentiation}
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int res = 1;
	while (n>0) {
		if (n&1) {
			res = (1LL*(res%m) * (x%m))%m;
		}
		x = (1LL * (x)%m * (x)%m)%m;
		n >>= 1;
	}
	return res;
}

// factorial of a number using modular exponentiation; M = 10^9+7
/*
Addition: (a + b)%M = ((a%M) + (b%M))%M
Subtraction: (a — b)%M = ((a%M) — (b%M) + M)%M
Multiplication: (a * b)%M = ((a%M) * (b%M))%M
*/
int factorialMod(int x, int m = 1e9+7) {
    int fac=1;
    if (x==0) {
        return 1;
    } else {
        fac = (1LL * (x)%m * (factorialMod(x-1))%m) %m;
        return fac;
    }
}

// incl-excl principle
int divisible(int n, int a, int b) { 
    int c1 = n / a;
    int c2 = n / b;
    int LCM = (a*b)/GCDeuII(a , b);
    int c3 = n / LCM;

    cout << "n: " << n << " | a: " << a << " | b: " << b << " | LCM: " << LCM << endl;

    return (c1 + c2 - c3); // divisible by a + divisible by b - divisible by both a and b
}
// TODO: 
// segmented seive [✓]
// pigeon hole principle
// catalon number
int main() {
    // code here
    // cout << "enter a number: ";
    // int n;
    // cin >> n;
    // cout << (isPrime(n) ? "Prime!!" : "Not prime!") << endl;

    // cout << "enter a number (0 -> n): ";
    // int n;
    // cin >> n;
    // cout << "Prime numbers in in range 0 -> " << n << ": " << countPrimes(n) <<  endl;
    // cout << "enter a, b: ";
    // int a,b;
    // cin >> a >> b;
    // cout << "GCD of " << a << "," << b << " is : " << endl << GCDnaive(a,b) << " " << GCDeuI(a,b) << " " << GCDeuII(a,b) << endl;

    // int T,x,n,m;
    // cin >> T;
    // while (T--) {
    //     cin >> x >> n >> m;
    //     cout << modularExponentiation(x,n,m) << endl;
    // }
    
    // cout << factorialMod(212) << " 1e9+7" << endl;

    int n = 100;
    int a = 10;
    int b = 25;
    cout << "Number of integers up to " << n << " divisible by " << a << " or " << b << ": " << divisible(n, a, b) << endl;
    
    return 0;
}
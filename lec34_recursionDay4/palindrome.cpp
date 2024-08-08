#include <iostream>
using namespace std;

bool isPalindrome(string& s,int i,int j) {
    if (i >= j) {
        return true;
    } else if (s[i] != s[j]) {
        return false;
    }
    return isPalindrome(s, i+1, j-1);
}

int main() {
    // code here
    string s1 = "kamla";
    cout << "palindrome? : " << ((isPalindrome(s1, 0, s1.length()-1)==1) ? "yes" : "no") << endl;

    string s2 = "naman";
    cout << "palindrome? : " << ((isPalindrome(s2, 0,s2.length()-1)==1) ? "yes" : "no") << endl;

    string s3 = "hello";
    cout << "palindrome? : " << ((isPalindrome(s3, 0, s3.length()-1)==1) ? "yes" : "no") << endl;

    string s4 = "racecar";
    cout << "palindrome? : " << ((isPalindrome(s4, 0, s4.length()-1)==1) ? "yes" : "no") << endl;

    string s5 = "level";
    cout << "palindrome? : " << ((isPalindrome(s5, 0, s5.length()-1)==1) ? "yes" : "no") << endl;

    return 0;
}
// void reverse(string& s,int n,int i=0) {
//     if (i > n-i-1) {
//         return;
//     } else {
//         swap(s[i],s[n-i-1]);
//         reverse(s,n,i+1);
//     }
// }
// bool isPalindrome(string& s) {
//     int n = s.length();
//     string str = s;
//     reverse(s,n);
//     return ((str == s) ? 1 : 0);
// }
// int main() {
//     // code here
//     string s1 = "kamla";
//     cout << "palindrome? : " << ((isPalindrome(s1)==1) ? "yes" : "no") << endl;
//     string s2 = "naman";
//     cout << "palindrome? : " << ((isPalindrome(s2)==1) ? "yes" : "no") << endl;

//     return 0;
// }
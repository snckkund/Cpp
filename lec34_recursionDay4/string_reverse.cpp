#include <iostream>
using namespace std;

void reverse(string& s,int n,int i=0) {
    if (i > n-i-1) {
        return;
    } else {
        swap(s[i],s[n-i-1]);
        reverse(s,n,i+1);
    }
}
int main() {
    // code here
    string s = "what's up?";
    cout << "before: " << s << endl;
    reverse(s,s.length());
    cout << "after: " << s << endl;
    return 0;
} 
// void reverse(string& s,int i, int j) {
//     if (i > j) {
//         return;
//     } else {
//         swap(s[i],s[j]);
//         reverse(s,i+1,j-1);
//     }
// }
// int main() {
//     // code here
//     string s = "abcde";
//     cout << "before: " << s << endl;
//     reverse(s,0,s.length()-1);
//     cout << "after: " << s << endl;
//     return 0;
// }

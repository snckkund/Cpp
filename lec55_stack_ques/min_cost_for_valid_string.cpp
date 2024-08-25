#include <iostream>
#include <stack>
using namespace std;

// @Code360:  Minimum Cost To Make String Valid

int findMinimumCost(string str) {
  // odd condition
  if(str.length()%2 == 1) {
    return -1;
  }

  stack<char> s;
  for(char ch:str) {
    if (ch == '{') {
      s.push(ch);
    }
    else {
      // ch is closed brace
      if(!s.empty() && s.top() == '{') {
        s.pop();
      }
      else {
        s.push(ch);
      }
    }
  }
  // stack contains invalid expression
  int a=0, b=0;
  while(!s.empty()) {
    if(s.top() == '{') {
      b++;
    }
    else {
      a++;
    }
    s.pop();
  }
  int ans = (a+1)/2 + (b+1)/2;
  return ans;
}

int main() {
    
    string str = "{{{{";
    cout << findMinimumCost(str) << endl;
    
    return 0;
}
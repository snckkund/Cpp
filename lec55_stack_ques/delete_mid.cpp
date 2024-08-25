#include <iostream>
#include <stack>
using namespace std;

// @Code360:  Delete middle element from stack

void solve(stack<int>&inputStack, int count, int size) {
   // base case
   if(count == size/2) {
      inputStack.pop();
      return;
   }

   int temp = inputStack.top();
   inputStack.pop();

   solve(inputStack, count+1,size);
   
   // back track
   inputStack.push(temp);

}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   solve(inputStack, count, N);
   
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

int main() {
    
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    printStack(s);

    deleteMiddle(s, 4);

    printStack(s);
    
    return 0;
}
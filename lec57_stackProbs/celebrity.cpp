#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// @Gfg: The Celebrity Problem

class Solution {
private:
    // Helper function to check if person 'a' knows person 'b'
    bool knows(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }

public:
    // Function to find if there is a celebrity in the party or not
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;
        
        // Step 1: Push all elements to stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Determine the potential celebrity
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            // If person 'a' knows person 'b', then 'a' cannot be a celebrity, push 'b'
            if (knows(mat, a, b)) {
                s.push(b);
            } 
            // If person 'a' does not know person 'b', then 'b' cannot be a celebrity, push 'a'
            else {
                s.push(a);
            }
        }

        // The single element in the stack is the potential celebrity
        int candidate = s.top();

        // Step 3: Verify the candidate
        // Row check: Ensure candidate does not know anyone
        bool rowCheck = true;
        for (int i = 0; i < n; i++) {
            if (mat[candidate][i] != 0) {
                rowCheck = false;
                break;
            }
        }

        // Column check: Ensure everyone knows the candidate
        bool colCheck = true;
        for (int i = 0; i < n; i++) {
            if (i != candidate && mat[i][candidate] != 1) {
                colCheck = false;
                break;
            }
        }

        // If both checks are true, candidate is a celebrity
        if (rowCheck && colCheck) {
            return candidate;
        } else {
            return -1;
        }
    }
};

int main() {
    
    Solution obj;

    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 0, 0},
                               {1, 1, 0}};

    int celeb = obj.celebrity(mat);
    
    cout << (celeb != -1 ? to_string(celeb) + " is the celebrity" : "No one is celebrity");
    
    return 0;
}
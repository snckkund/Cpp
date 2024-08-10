#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& mat) {
        if ((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && mat[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }
    void solve(vector<vector<int>>& mat, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        // reached x,y
        // basecase
        if (x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // four choices: D L R U

        // down
        int newx = x+1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, mat)){
            path.push_back('D');
            solve(mat, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // left
        newx = x;
        newy = y-1;
        if (isSafe(newx, newy, n, visited, mat)){
            path.push_back('L');
            solve(mat, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // right
        newx = x;
        newy = y+1;
        if (isSafe(newx, newy, n, visited, mat)){
            path.push_back('R');
            solve(mat, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // up
        newx = x-1;
        newy = y;
        if (isSafe(newx, newy, n, visited, mat)){
            path.push_back('U');
            solve(mat, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0;
    }
public:
    void print(vector<string>& str) {
        cout << "{";
        for (string i:str) {
            cout << "\"" << i << "\"" << (i!=str[str.size()-1]?",":"");
        }cout << "}" << endl;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;

        if (mat[0][0] == 0) {return ans;}
        
        int srcx = 0;
        int srcy = 0;

        vector<vector<int>> visited = mat;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(mat, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(),ans.end());

        return ans;
    }
};

int main() {
    Solution obj;
    // Test case: 1
    vector<vector<int>> mat1 = {{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<string> out1 = obj.findPath(mat1); // {"DDRDRR", "DRDDRR"}
    obj.print(out1);
    // Test case: 2
    vector<vector<int>> mat2 = {{1, 0},
                                {1, 0}};
    vector<string> out2 = obj.findPath(mat2); // {}
    obj.print(out2);  
    // Test case: 3
    vector<vector<int>> mat3 = {{1, 1, 1},
                                {0, 0, 1}, 
                                {0, 0, 1}};
    vector<string> out3 = obj.findPath(mat3); // {"RRDD"}
    obj.print(out3);            
    // Test case: 4
    vector<vector<int>> mat4 = {{1, 1, 1},
                                {1, 1, 0}, 
                                {1, 1, 1}};
    vector<string> out4 = obj.findPath(mat4); // {"DDRR","DRDR","RDDR","RDLDRR"}
    obj.print(out4);  
    // Test case: 5
    vector<vector<int>> mat5 = {{1}};
    vector<string> out5 = obj.findPath(mat5); // {""}
    obj.print(out5);  
    // Test case: 6
    vector<vector<int>> mat6 = {{1, 0, 1, 1},
                                {1, 1, 1, 0}, 
                                {0, 1, 0, 1},
                                {1, 1, 1, 1}};
    vector<string> out6 = obj.findPath(mat6); // {"DRDDRR"}
    obj.print(out6);  
    // Test case: 7
    vector<vector<int>> mat7 = {{1, 1},
                                {1, 1}};
    vector<string> out7 = obj.findPath(mat7); // {"DR", "RD"}
    obj.print(out7);  
    // Test case: 8
    vector<vector<int>> mat8 = {{1, 0, 1, 1},
                                {1, 1, 1, 1}, 
                                {0, 1, 0, 1},
                                {1, 1, 1, 1}};
    vector<string> out8 = obj.findPath(mat8); // {"DRDDRR","DRRRDD","DRRURDDD"}
    obj.print(out8);  

    return 0;
}
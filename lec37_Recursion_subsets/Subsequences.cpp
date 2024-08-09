#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subsequences
{
private:
    void solve (string& str, int index, string output, vector<string>& ans) {
        if ((index >= str.length())) {
            if (output.length())
                ans.push_back(output);
            return;
        }
        // exclude
        solve (str, index+1, output, ans);
        // include
        char element = str[index];
        output+=element;
        solve (str, index+1, output, ans);
    }
public:
    void print(vector<string>& str) {
        cout << "{";
        for (string i:str) {
            cout << "\"" << i << "\"" << (i!=str[str.size()-1]?",":"");
        }cout << "}" << endl;
    }
    vector<string> out(string& str) {
        vector<string> ans;
        string output="";
        int index = 0;
        solve (str, index, output, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    // code here
    Subsequences obj;
    string str1 = "abc";

    vector<string> ans1 = obj.out(str1);
    obj.print(ans1); // {"","a","b","c","ab","ac","bc","abc",}

    return 0;
}
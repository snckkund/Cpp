#include <iostream>
#include <vector>
using namespace std;

class phoneKeyPad
{
private:
    void solve (string& digits, string output, int index, vector<string>& ans, string* mapping) {
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];
        for (int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            output.pop_back();
        }
    }
public:
    void print(vector<string>& str) {
        cout << "{";
        for (string i:str) {
            cout << "\"" << i << "\"" << (i!=str[str.size()-1]?",":"");
        }cout << "}" << endl;
    }
    vector<string> letterCombinations(string digits) {
        
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; // [2-9]
        vector<string> ans;
        string output = "";
        int index = 0;
        if (digits.length()==0) return ans;

        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

int main() {
    // code here
    phoneKeyPad obj;
    string d1 = "23";

    vector<string> ans1 = obj.letterCombinations(d1);
    obj.print(ans1); // {"ad","ae","af","bd","be","bf","cd","ce","cf"}

    return 0;
}
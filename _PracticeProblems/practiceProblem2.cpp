#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
/**
 * @Question: permutations of string II
 */
class practice 
{
private:
    void solve(string& str, string output, vector<string>& ans, int lvlcount, int level) {
        if (lvlcount == level) {
            ans.push_back(output);
            return;
        }
        for (int i=0; i<str.length(); i++) {
            output.push_back(str[i]);
            solve(str, output, ans, lvlcount+1,level);
            // backtrack
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
    vector<string> permutations(string& str, int level) {
        vector<string> ans;
        string output = "";
        int lvlcount = 0;
        solve(str, output, ans, lvlcount, level);
        return ans;
    }
};

int main() {

    practice obj;
    // Test case 1: Empty string
    string str1 = "";
    int level1 = 3;
    vector<string> ans1 = obj.permutations(str1, level1);
    assert(ans1.empty());
    // Test case 2: Single character string
    string str2 = "a";
    int level2 = 2;
    vector<string> ans2 = obj.permutations(str2, level2);
    assert(ans2 == vector<string>{"aa"});
    // Test case 3: Two character string
    string str3 = "ab";
    int level3 = 2;
    vector<string> ans3 = obj.permutations(str3, level3);
    vector<string> check3 = {"aa", "ab", "ba", "bb"};
    assert(ans3 == check3);
    // Test case 4: Two character string , level 3
    string str4 = "ab";
    int level4 = 3;
    vector<string> ans4 = obj.permutations(str4, level4);
    vector<string> check4 = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"};
    assert(ans4 == check4);
    // Test case 5: number string
    string str5 = "01";
    int level5 = 3;
    vector<string> ans5 = obj.permutations(str5, level5);
    vector<string> check5 = {"000", "001", "010", "011", "100", "101", "110", "111"};
    assert(ans5 == check5);
    // Test case 6: Three character string
    string str6 = "abc";
    int level6 = 2;
    vector<string> ans6 = obj.permutations(str6, level6);
    vector<string> check6 = {"aa","ab","ac","ba","bb","bc","ca","cb","cc"};
    assert(ans6 == check6);

    cout << "All test cases passed!" << endl;
    
    return 0;

}
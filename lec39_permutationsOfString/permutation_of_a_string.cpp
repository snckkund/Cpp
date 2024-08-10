#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
/**
 * @Code360: Permutations of a String
 * @Leetcode: {46. permutations}
 */
class permutation {
    void solve(string &str, int index, vector<string>& ans) {
        if (index > str.length()-1) {
            ans.push_back(str);
            return;
        }
        for (int i=index; i<str.length(); i++) {
            swap(str[i],str[index]);
            solve(str,index+1,ans);
            // back track
            swap(str[i],str[index]);
        }
    }
public:
    void print(vector<string>& str) {
        cout << "{";
        for (string i:str) {
            cout << "\"" << i << "\"" << (i!=str[str.size()-1]?",":"");
        }cout << "}" << endl;
    }
    vector<string> generatePermutations(string &str) {
        // write your code here
        int index = 0;
        vector<string> ans;
        solve(str, index, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    // code here
    permutation obj;
    // string s1 = "abc";
    // vector<string> ans1 = obj.generatePermutations(s1);
    // obj.print(ans1); // { “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }

    // Test case 1: Empty string
    string s1 = "";
    vector<string> ans1 = obj.generatePermutations(s1);
    assert(ans1.empty());
    // Test case 2: Single character string
    string s2 = "a";
    vector<string> ans2 = obj.generatePermutations(s2);
    assert(ans2 == vector<string>{"a"});
    // Test case 3: String with repeated characters
    string s3 = "ab";
    vector<string> ans3 = obj.generatePermutations(s3);
    vector<string> check3 = {"ab", "ba"};
    assert(ans3 == check3);
    // Test case 4: String with all distinct characters
    string s4 = "abc";
    vector<string> ans4 = obj.generatePermutations(s4);
    vector<string> check4 = {"abc", "acb", "bac", "bca", "cab", "cba"};
    assert(ans4 == check4);
    cout << "All test cases passed!" << endl;

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int getLength(char* ch) {
    int count = 0;
    for (int i=0; ch[i]!='\0'; i++) {
        count++;
    } return count;
}

void reverseString(char ch[]) {
    int s=0;
    int e=getLength(ch)-1;
    while(s<e) {
        swap(ch[s++],ch[e--]);
    }
}

// @Code360: {Replace Spaces}
string replaceSpaces(string &str) {
    string re;
    for (char c : str) {
        if (c == ' ') {
            re += "@40";
        } else {
            re += c;  
        }
    }
    return re;
}

class Solution {
public:
    // @Leetcode {# 125. Valid Palindrome}
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            else {
                start++;
                end--;
            }
        }
        return true;
    }

    // @Gfg: Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        char maxc;
        int maxi = 0;
        for (int i=0; i<str.length(); i++) {
            int count = 0;
            for (int j=0; j<str.length(); j++) {
                if(str[j]==str[i]) {
                    count++;
                }
            }
            if (count>maxi || (count==maxi && str[i]<maxc)) {
                maxi=count;
                maxc=str[i];
            }
        }
        return maxc;
    }

    // @Leetcode {# 1910. Remove All Occurrences of a Substring}
    string removeOccurrences(string s, string part) {
        while (s.length()!=0 && s.find(part)<s.length()) {
            s.erase(s.find(part),part.length());
        }
        return s;
    }

    // @Leetcode {# 567. Permutation in String}
    bool checkEqual(int a[26], int b[26]) {
        for (int i=0; i<26; i++) {
            if (a[i]!=b[i]) {
                return 0;
            }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for (int i=0; i<s1.length(); i++) {
            int index = s1[i]-'a';
            count1[index]++;
        }
        int i=0;
        int windowSize = s1.length();
        int count2[26]={0};

        while (i<windowSize && i<s2.length()) {
            int index = s2[i]-'a';
            count2[index]++;
            i++;
        }
        if (checkEqual(count1,count2)) {
            return 1;
        }
        while (i<s2.length()) {
            char newChar=s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldchar = s2[i-windowSize];
            index = oldchar-'a';
            count2[index]--;

            i++;

            if (checkEqual(count1,count2)) 
                return 1;
        }
        return 0;
    }

    // @Leetcode {# 1047. Remove All Adjacent Duplicates In String}
    string removeDuplicates(string s) {
        string temp = "";
        int i = 0;
        while(i < s.length()){
            if(temp.empty() || s[i] != temp.back()){
                temp.push_back(s[i]);
            } else{
                temp.pop_back();
            }
            i++;
        }
        return temp;
    }

    // @Leetcode {# 443. String Compression}
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while(i < n){
            int j = i+1;

            while (j<n && chars[i]==chars[j]) {
                j++;
            }

            chars[ansIndex++]=chars[i];
            int count = j-i;

            if (count > 1) {
                string cnt = to_string(count);
                
                for (char ch:cnt) {
                    chars[ansIndex++]=ch;
                }
            }
            i=j;
        }
        return ansIndex;
    }

};

int main() {

    // char name[20];
    // cout << "enter your name: ";
    // cin >> name; // chandu
    // // name[2] = '\0'; // ch
    // cout << "your name is " << name << endl;
    // cout << "length of the input is " << getLength(name) << endl;

    // reverseString(name);
    // cout << "reverse: " << name << endl;

    Solution obj;
    // cout << "palindrome? : " << obj.isPalindrome("c1 O$d@eeD o1c") << endl;
    // cout << "palindrome? : " << obj.isPalindrome("A1b22Ba") << endl;

    // cout << "maximum occurence: " << obj.getMaxOccuringChar("template") << endl;
    // cout << "maximum occurence: " << obj.getMaxOccuringChar("dabacbcd") << endl;
    // cout << "maximum occurence: " << obj.getMaxOccuringChar("f") << endl;

    // string s1 = "I love coding";
    // string s2 = "Hello";
    // cout << replaceSpaces(s1) << endl;
    // cout << replaceSpaces(s2) << endl;

    // string s = "daabcbaabcbc";
    // cout << "after removing substring occurences: " << obj.removeOccurrences(s,"abc") << endl;

    // string s2 = "eidbaooo";
    // string s1 = "ab";
    // string s21 = "eidboaoo";
    // cout << "s1 exist in s2? : " << obj.checkInclusion(s1,s2) << endl;
    // cout << "s1 exist in s21? : " << obj.checkInclusion(s1,s21) << endl;

    // string s1 = "abbaca";
    // string s2 = "azxxzy";
    // cout << "remaining string: " << obj.removeDuplicates(s1) << endl;
    // cout << "remaining string: " << obj.removeDuplicates(s2) << endl;

    // vector<char> chars1 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    // vector<char> chars2 = {'a'};
    // vector<char> chars3 = {'a','a','b','b','c','c','c'};
    // cout << "answer index: " << obj.compress(chars1) << endl;
    // cout << "answer index: " << obj.compress(chars2) << endl;
    // cout << "answer index: " << obj.compress(chars3) << endl;

    return 0;
}
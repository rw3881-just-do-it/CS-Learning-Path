/*
given two strings and see whether s is a substring of t.
substring is defined as a new string that is formed from the original
string by deleting some of the characters without disturbing the relative
positions of the remaining characters

-intuition: double loop (which takes time and is easy to make it wrong)
-better solution: use increament on index and check the length
-the other way but same idea: use two pointers and while loop
*/
#include <iostream>
#include <string>
using namespace std;

bool isSubsequence (const string& s, const string& t){
    int index = 0;
    for (size_t j = 0; j < t.size(); ++j){
        if (index < s.size() && s[index] == t[j]){
            ++index;
        }
    }
    return index == s.size();
}

int main(){
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t);
}
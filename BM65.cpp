/*
given two strings. return the longest common substring. if there is none, return -1

-the order matters here, so, we keep track of the number inside the longest common substring
using a table so that the order can be properly kept!
-then, after fill in the table, we check which char is skipped (not in the common substring)
from the right-down corner to upwards - check the second loop
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string largestCommonString(string s1, string s2){
    //create a table storing the length of the largest common string
    //at the point of comparing each of s1 to all of the s2
    vector<vector<int>> sameIndex(s1.size(), vector<int> (s2.size() + 1, 0));
    for (size_t i = 1; i <= s1.size(); ++i){
        for (size_t j = 1; j <= s2.size(); ++j){
            //if characters is the same, increase common string
            if (s1[i - 1] == s2[j - 1]){
                sameIndex[i][j] = sameIndex[i - 1][j - 1] + 1;
            }
            //skip one char from either string
            else{
                sameIndex[i][j] = max(sameIndex[i - 1][j], sameIndex[i][j - 1]);
            }
        }
    }
    string res = "";
    int i = s1.size();
    int j = s2.size();
    while (i > 0 && j > 0){
        //this char is in common string, so diagonal up
        if (s1[i - 1] == s2[j - 1]){
            res += s1[i - 1];
            --i;
            --j;
        }//if cell above is bigger, then s1[i] is not in the common string. go directly up
        else if(sameIndex[i - 1][j] > sameIndex[i][j - 1]){
            --i;
        }//s2[j] is not in the common string, go directly left
        else{
            --j;
        }

    }
    reverse(res.begin(), res.end());
    return res.empty() ? "-1" : res;
}

int main(){}
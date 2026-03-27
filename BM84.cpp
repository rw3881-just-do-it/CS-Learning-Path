#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
find the longest prefix in a given set of strings
-pretty intuitive
*/
string longestCommonPrefix(vector<string>& strs){
    if (strs.size() == 0){
        return "";
    }
    for (size_t i = 0; i < strs[0].length(); ++i){
        char temp = strs[0][i];
        for (size_t j = 1; j < strs.size(); ++j){
            if (i == strs[j].length() || strs[j][i] != temp){
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main(){

}
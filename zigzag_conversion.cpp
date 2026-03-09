/*
given a string that reads from vertical following this pattern (if row num == 4)
A     G
B   F H
C E   I
D     J
the given string is "ABCDEFGHIJ", write an algorithm that convert it as
"AGBFHCEIDJ"
*/

#include <iostream>
#include <string>
using namespace std;

string convert(const string& s, int numRows){
    if(numRows <= 1){
        return s;
    }
    string res = "";
    size_t cycle = 2*numRows - 2;
    for (size_t i = 0; i < numRows; ++i){
        for (size_t j = i; j < s.size(); j += cycle){
            res.push_back(s[j]);
            //finds the diagonal letters: diagonal step occurs at s[cycle - i]
            //since j = i, then the step occurs at j + cycle - 2*i
            //since top row has no diagonal characters, i != 0
            //since botrom row has no diagonal characters, i != numRows - 1
            //since can not exeed boundary, j + cycle - 2*i < s.size()
            if (i != 0 && i != numRows - 1 && j + cycle -2*i < s.size()){
                res.push_back(s[j + cycle - 2*i]);
            }
        }
    }
    return res;
}

int main(){
    string s = "ABCDEFGHIJ";
    string res = convert(s, 4);
    for (size_t i = 0; i < s.size(); ++i){
        cout << res[i];
    }
}
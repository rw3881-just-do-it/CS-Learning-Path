/*given a number, convert it into a string composed by A-Z

-26-base with A-Z representation
-reflection: let's go with how the computer works, 0-25
if we use 64 + number% 26, trying to avoid the outrange issue,
it will fail at number as a multiple of 26, which is very hard to solve.
-so at the beginning of each loop, we deduce number 1 less instead of add up to c
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string convertToTitle(int columnNumber){
    string res = "";
    char c = 65;
    while (columnNumber != 0){
        columnNumber --; // very important! computer count from 0 - 25
        c = 65 + columnNumber % 26;
        columnNumber = columnNumber / 26;
        res = res + c;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string res = convertToTitle(52);
    cout << res;
    return 0;
}
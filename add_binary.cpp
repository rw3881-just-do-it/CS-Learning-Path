/*add_binary.cpp
-similar to add to array form--the unity to convert
different types of numbers
-only need to take care of the nature of string,
so convert char into digits by -'0' 
and convert digit to char by + '0' */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b){
    string res;
    int increament = 0;
    int lena = a.size()-1;
    int lenb = b.size()-1;
    while (lena>=0 || lenb>=0 || increament == 1){
        if (lena >= 0){
            increament += a[lena--] - '0';
        }
        if (lenb >= 0){
            increament += b[lenb--] - '0';
        }
        res += increament % 2 + '0';
        increament /= 2;
    }
    reverse(begin(res), end(res));
    return res;
}
int main(){
    return 0;
}
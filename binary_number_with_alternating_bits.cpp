/*give a positive integer, check whether its two adjacent
bits will always have different values

-I think we need to use XOR
shifting it right for 1 bit is opposite pattern if it is true,
so when we XOR the original and the XORed number, it should
be 11111... -> so how to check this??
-adding it by 1. eg 1+1 = 10,
and once we 1 = 01 & 10 then it must be 0!
so right shift - XOR - & (+1)!

-another way - convert the 2-bits to strings and iterate
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool hasAlternatingBits(int n){
    unsigned int m = n ^ (n >> 1); // or will be a memory overflow, it is safer
    return m & (m+1) == 0;
}

bool stringSolution(int n){
    string bits = "";
    if (n == 0){
        bits = "0";
    }else{
        while (n > 0){
            //%2 to access the least significant bit and convert it to a character
            bits += (n % 2) + '0';
            //right shift the number by 1, equal to integer divided by 2
            n >>= 1;
        }
    }
    reverse(bits.begin(), bits.end());
    for (size_t i = 1; i < bits.length(); i++){
        if (bits[i - 1] == bits[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 5;
    cout << stringSolution(n);
    return 0;
}
/* Preparing to celebrate Lunar New Year!
reverse_bits.cpp
-bits manipulation
-reverse the order of bits

the reversed is input from front to back,
the needed reversed is input from back to front*/
#include <iostream>
using namespace std;

int reverseBits(int n){
    int res = 0;
    for (int i = 0; i < 32; i++){
        res <<= 1; //make room for the next bit, one step
        res |= (n & 1); // copy lowest bit of n into res
        n >>= 1; //shift n to the second lowest to process the next bit
    }
    return res;
}

int main(){
    int n = 43261596;
    int res = reverseBits(n);
    cout << res << endl;
    return 0;
}
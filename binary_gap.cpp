/*
binary_gap.cpp

return the maximum gap between two consequtive ones in a number's
binary representation

-intuition: sliding window, with index manually added
*/
#include <iostream>
#include <algorithm>
using namespace std;

int binaryGap(int n){
    int prev = -1;
    int curr = 0;
    int max = 0;
    while (n > 0){
        if(n & 1){
            if (prev != -1){ // check whether it is the first one
                if (curr - prev > max){
                    max = curr - prev;
                }
            }
            prev = curr;
        }
        n = n/2;
        curr ++;
    }
    return max;
}

int main(){
    cout << binaryGap(5) << endl;
}
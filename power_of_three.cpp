/*given an integer, check whether it is the power of three

-be careful, if n <= 0, then return false directly!

-intuition: loop with division,
with the condition as n % 3 in a while loop, and then check whether
the remaining n is equal to 1.

-another way: consider it is in the int range, the largest 3's power is
3^19 = 1162261467. if it can divide n, then n must be a power of 3.

-lesson learned: consider the property of the number, and then play with it,
and make a judgement
*/
#include <iostream>
using namespace std;

bool isPowerOfThree(int n){
    if (n % 2 == 0 || n <= 0){
        return false;
    }
    while (n % 3 == 0){
        n = n / 3;
    }
    return n == 1;
}

bool secondIsPowerOfThree(int n){
    if (n <= 0){
        return false;
    }
    return 1162261467 % n == 0;
}

int main(){
    cout << secondIsPowerOfThree(3) << endl;
    return 0;
}
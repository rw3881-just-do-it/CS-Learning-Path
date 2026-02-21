/*
return the count of numbers in the inclusive range having a prime
number of set bits in their binary representation

-intuition: loop through the range and call a helper function,
which counts and returns the number of set bits in a given int.

-potential risk! in the loop we checked prime numbers that are less
than 20, because we know the biggest possible number in the given
range is 10E6. 
-a 23-bit binary number can represent decimal values up to 8388604,
and a 19-bit binary number can represent decimal values up to 524287,
so we are safe to compare to 19 (it is usless to compare to prime
that's bigger than 19 due to the given range)
*/
#include <iostream>
using namespace std;

int countOne(int n){
    int tot = 0;
    while (n != 0){
        if((n%2)&1){
            tot += 1;
        }
        n = n/2;
    }
    return tot;
}

int countPrimeSetBits(int left, int right){
    int sum = 0;
    for (int i = left; i <= right; i++){
        int n = countOne(i);
        if (n == 2 || n == 3 || n == 5 || n== 7 || n == 11
            || n == 13 || n == 17 || n == 19){
                sum += 1;
            }
    }
    return sum;
}
int main(){
    cout << countPrimeSetBits(10, 15) << endl;
}
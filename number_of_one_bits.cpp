/*happy lunar new year!
return the number of one bits in a given unsigned integer - Hamming Weight

-intuition: loop 32 times and count 1
-law : n = n & (n - 1), n is the numer eliminated the right most 1
*/
#include <iostream>
using namespace std;

int hammingWeight(int n){
    int count = 0;
    for (int i = 0; i < 32; i++){
        if ((n >> i) & 1){ //right shift 1 and compare to 1 (using equal)
            count ++;
        }
    }
    return count;
}

int secondHammingWeight(int n){
    int count = 0;
    while(n != 0){
        n = n & (n - 1); // get rid of the right most 1
        count ++;
    }
    return count;
}

int main(){
    int n = 11;
    int res = hammingWeight(11);
    cout << res;
}
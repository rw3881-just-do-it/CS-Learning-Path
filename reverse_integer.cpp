/*
given a signed 32-bit integer x, return x with its digits reversed.

-separate the digits and multiple them up again
 - need to be mindful about the out off range of int max and int min (since it can be negative)

INT_MAX = 2147483647
INT_MIN = -2147483648
*/

#include <iostream>
#include <vector>
using namespace std;

int reverse(int x){
    vector<int> digit;
    while (x != 0){
        digit.push_back(x % 10);
        x /= 10;
    }
    long long result = 0;
    long increment = 1;
    for (size_t i = digit.size(); i > 1; --i){
        result += digit[i - 1] * increment;
        increment *= 10;
    }
    if (result > INT_MAX || result < INT_MIN){
        return 0;
    }
    return (int)result;
}

int secondTry(int x){
    int res = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        if (res > INT_MAX/10 || res < INT_MIN/10){ //going to multiply by ten,
            //so this check is a must to prevent overflow
            return 0;
        }
        if (res == INT_MAX/10 && digit > 7){
            return 0;
        }
        if (res == INT_MIN/10 && digit < -8){
            return 0;
        }
        res = res * 10 + digit;
    }
    return res;
}

int main(){
    cout << secondTry(1534236469) << endl;
}
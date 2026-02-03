/*add to array form of integer*/
/*
add the number stored in num and integer k digit by digit,
starting from the least significant digit (right to left).
In each iteration add:
-the current digit from num(if any)
-the current digit from k (if any)
-a increament from the previous digit addition--iteration together in iteration using a separate variable
The loop continues as long as there is still a digit to process
in num or in k or increament remains

each iteration produces one result digit and updates the carry,
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k){
    int index = num.size() - 1;
    int increament = 0;
    while (index >= 0 || k > 0 || increament > 0) {
        int digit;
        if(k > 0) { //separate digit by digit
            digit = k % 10;
            k = k / 10;
        }
        else {
            digit = 0;
        }
        //because loop in or, so need to check each condition
        if(index >= 0) { //no need to add more integer
            int sum = num[index] + digit + increament; //use sum to store
            num[index] = sum % 10;
            increament = sum / 10; // seperate increament with each iteration, avoid power
            index--;
        } 
        else {
            int sum = digit + increament;
            num.insert(num.begin(), sum % 10); // a new function
            increament = sum / 10;
        }
    }
    return num;
}

int main(){
    return 0;
}
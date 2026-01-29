#include <iostream>
#include <string>
using namespace std;

class MySolution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (size_t i = 0; i < (s.size())/2; i++){
            if (s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};

/*
if it is negative, return false;
if it is not negative,
calculate a new number based on the digits from the last to first, 
using normal seperating techniques (%, / and *10 in a while loop)
then compare whether the new created one is the same as the original one.
*Why this work: the new digit is actually the reversed orginal number, if the reversed is
the same as the original, then the original is palidrome number*/

class GoodSolution{
    public:
        bool isPalidrome(int x){
            if (x < 0){
                return false;
            }
            int num = x;//a copy of x so no interference to x within the scope
            long long reversed = 0; //has to be long long or there will be an overflow issue
            //eg. INT_MAX = x = 2147483647
            // reversed = 7463847412 exceeds int!
            while (num != 0){
                reversed = reversed * 10 + num % 10; //this reversed * 10 is where overflow could happen
                num = num / 10;
            }
            return (reversed == x);
        }
};
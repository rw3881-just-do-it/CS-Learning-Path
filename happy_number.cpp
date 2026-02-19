/*check whether a number is a happy number
a happy number is a number that iterates using it's digits' sqaure sums
and then see whether it ends up in 1. if it ends in one, then it is a happy number

-reflection: difficult to handle the infinite loop WITHOUT 1,
so we stop when we see result one, and for the rest the next = previous, we return false

-thus, we use slow and fast pointers, since there is a cycle detection

-in each cycle, slow moves 1 step while fast move 2 steps,
and the speed difference is what we want
*/

#include <iostream>
#include <fstream>
using namespace std;

int digitSquare(int n){
    int sum = 0;
    while (n != 0){
        int temp = n % 10;
        sum += temp * temp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    int slow = n;
    int fast = n;
    do{
        slow = digitSquare(slow);
        fast = digitSquare(fast);
        fast = digitSquare(fast); // to make a fast pointer fast, one more time!
        //we need to put the fast inside the do loop to ensure the speed difference
        //if not, then the two pointers would move at the same speed
        if (fast == 1){
            return true;
        }
    } while (slow != fast);
    return false;

}

int main(){
    cout << isHappy(2);
    return 0;
}
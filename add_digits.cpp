/*give an integer num, repeatedly add all its digits until the result
has only one digit, and return it

-intuition: nested loop or recursion (see intuitiveAddDigits)
-or, mathmatically, the result would be 1 + (num - 1) % 9.
explanation is after int main(){}
*/
#include <iostream>
using namespace std;

int addDigits(int num){
    if (num == 0){
        return 0;
    }
    return 1+(num - 1) % 9;
}

int intuitiveAddDigits(int num){
    if (num == 0){
        return 0;
    }
    if (num < 10){
        return num;
    }
    return intuitiveAddDigits((num/10)+(num%10));
}

int main(){
    cout << intuitiveAddDigits(38);
}

/*explanation:
let's list out:
1 - 1
2 - 2
3 - 3
...
9 - 9
and then
10 - 1 - 1
11 - 2 - 2
...
18 - 9 - 9
and then
19 - 20 - 2 - 2
20 - 2
21 - 3 - 3
...
99 - 18 - 9 - 9
...
so you see, the added integer would always go
back to the previous results, which will all 
falls into the case of % 9
-this should be able to be proved by math:
for every non-negative integer N, the remainder of N when divided by 9
is equal to the remainder of the sum of its decimal digits when divided
by 9.*/
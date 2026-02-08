/*climbing_stairs.cpp
-think about the patterns and divide the steps, WRITE DOWN EXAMPLES,
and descovered the results are actually febonacci numbers.
-see the notes at the bottom
*/
#include <iostream>
using namespace std;

int climbStairs(int n){
    int previous = 1;
    int temp = 0;
    int res = 1;
    int i = 1;
    while (i != n){ //1 2
        temp = res; //temp = 1 2
        res = res + previous; // res = 1+1=2 2+1=3
        previous = temp; //previous = 1
        i++; //2
        
    }
    return res;
}

/*memory usage slightly optimized version - not have i and temp defined
in the whole function scope but only in the loop
*/
//(also a for loop version)
int secondClimbStairs(int n){
    int prev = 1;
    int curr = 1;
    for(int i = 2; i <= n; i++){
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}

int main(){
    int res = climbStairs(4);
    cout << res << endl;
    return 0;
}
/*
1 - 1
//one - 1

2 = 1 + 1 = 0 + 2 - 2
//climb one step - left 1
//1 * two - 1

3 = 1 + 1 + 1 = 1 + 2 = 2 + 1 - 3
//climb one step - left 2
//climb two steps -  left 1
//1 * 3 - 1

4 
//climb one step - left 3
//climb two steps - left 2
//climb three first -  left 1
//1* four - 1

//same thoughts for the beyond

the reason to use addition instead of multiplication (yeah i used that first)
is because we have already make the situations in each separate case;
in other words, each climb-first-then-number-left pattern is independent of one another.
so we use addtion.
*/
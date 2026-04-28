/*total ways to go upstairs*/
#include <iostream>
using namespace std;
int jumpFloor(int number){
    if(number == 1){
        return 1;
    }
    int prev = 1;
    int next = 1;
    int curr = 0;
    for (int i = 2; i <= number;++i){
        curr = prev + next;
        prev = next;
        next = curr;
    }
    return curr;
}
int main(){
    cout << jumpFloor(7) << endl;
}
/*another way to code it is using recursion, but be mindful that stair(n) = fibonacci (n+1)*/

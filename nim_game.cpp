/*nim_game
-this is more like a math problem rather than a coding one lol

-rules:
there is a heap of stones on the table, you and your friend alternate taking turns
and you go first.
on each turn, the person whose turn it is will remove 1 to 3 stones from the heap,
and the one who removes the last stone is the winner.

-intuition:
when there is 3 + 1 = 4 stones, you will always lose.
when there is multiple 4 numbers of stones, you will also always lose,
because you move first. your opponent can thus always reduce the number
of the stones left to another multiple of 4, and ultimately make it a 4,
and so you lose;
but when there are other numbers, 1 - you win, 2 - you win, 3 - you win,
5 - you win as long as you only take 1, making your opponent to be the 
first hand at the situation of 4; the other numbers, same logic
*/
#include<iostream>
using namespace std;

bool canWinNim(int n){
    if (n%4 == 0){
        return false;
    }
    return true;
}

int main(){
    return 0;
}
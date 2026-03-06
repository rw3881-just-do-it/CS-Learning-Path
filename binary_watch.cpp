/*a binary watch has 4 LEDs on the top to represent hours 
and 6 LEDs on the bottom to represent the minutes
------------
8 4 2 1
32 16 8 4 2 1
------------
given an integer which represnets the number of LEDs that's
currently on, and return all possible times the watch could represent

-a way to think of it: jump out of the number of combination!
we can see the numbers in numbers of 1s, which would be:
-----------------
1 1 1 1
1 1 1 1 1 1
-----------------
which means that adding up the numbers would be exactly the integer!
we do not need to worry about the valid time, since we just go
happily through the valid time loop!

-SO JUMP OUT OF THE CAGE

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countBits(int x){
    int res = 0;
    while (x){
        if (x % 2 == 1){
            ++res;
        }
        x = x / 2;
    }
    return res;
}

vector<string> readBinaryWatch(int turnedOn){
    vector<string> res;
    if (turnedOn > 8){
        return res;
    }
    if (turnedOn == 0){
        res.push_back("0:00");
        return res;
    }
    for (size_t h = 0; h < 12; ++h){//hour loop
        for (size_t m = 0; m < 60; ++m){//minute loop
            if (countBits(h) + countBits(m) == turnedOn){
                //format
                string time = to_string(h) + ":";
                if (m < 10){
                    time += "0";
                }
                time += to_string(m);
                res.push_back(time);
            }
        }
    }
    return res;
}

int main(){
}
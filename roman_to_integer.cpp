/*Roman to Integer
-combination of letters under previous smaller than current for minus value*/

#include <iostream>
#include <string>

using namespace std;

/*
intuition: relation between two elements
choice: compare to previous or after->increament of steps after a combined condition
edge case: single letter->the loop assumes more than 1 element,
so handle the single or none letter separately.

-trouble met:
did compare to after first...the previous in the description could be a hint!
did not test the single/none letter case
*/
class MySolution {
public:
    int corresponding(char c){
        if (c == 'I'){
            return 1;
        }
        if (c == 'V'){
            return 5;
        }
        if (c == 'X'){
            return 10;
        }
        if (c == 'L'){
            return 50;
        }
        if (c == 'C'){
            return 100;
        }
        if (c == 'D'){
            return 500;
        }
        if (c == 'M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        if (s.size() == 0){
            return 0;
        }
        if (s.size() == 1){
            return corresponding(s[0]);
        }
        int num = 0;
        for (size_t i = 1; i < s.size(); i++){
            int val_prev = corresponding(s[i-1]);
            int val = corresponding(s[i]);
            if (val_prev < val){
                num = num + val - val_prev;
                i++;
            }
            else{
                num = num + val_prev;
            }
        }
        int val_last_prev = corresponding(s[s.size()-2]);
        int val_last = corresponding(s[s.size()-1]);
        if (val_last_prev >= val_last){
            num = num + val_last;
        }
        return num;
    }
};



int main(){
    return 0;
}
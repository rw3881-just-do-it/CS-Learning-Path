/*to test whether a given string is a palidrome, the characters in consideration only includes numbers and letters

-same idea as the other palidrome question
-unify the contents, and then make judgements

-an idea I employed: mark the proper location and do less iterations for checking!*/
#include <iostream>
#include <string>

using namespace std;

bool isPalidrome(string& s){
    int index = -1;
    for(size_t i = 0; i < s.size(); i++){
        if ((s[i]<='Z' && s[i]>='A') || (s[i]<='z' && s[i]>='a' || (s[i] >= '0' && s[i] <= '9'))){
            index ++;
            if(s[i]<='Z' && s[i]>='A'){
                s[i] = s[i] + 32;
            }
            s[index] = s[i];
        }
    }
    if(index == -1){
        return true;
    }
    for(size_t i = 0; i <= index/2; i++){
        if(s[i] != s[index - i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    s = "0P";
    bool res = isPalidrome(s);
    cout << res;
    return 0;
}
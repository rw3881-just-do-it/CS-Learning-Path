/* given a vector of strings, return the first palidrome string in the vector

-intuitively, do a for loop, and that works
-optimized version: 
using "for each" loop using const reference to decrease memory usage,
using two pointers in a while loop
using a bool, set it as TRUE first and then change it to false <- solve my issue thinking about the first solution

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string firstPalidrome(vector<string>& words){
    for(size_t i = 0; i < words.size(); i++){
        string s = words[i];
        int j = 0;
        int index = s.size()-1;
        for(j = 0; j <= index /2; j++){
            if(s[j] != s[index-j]){
                break;
            }
            if((j == index/2) && (s[j] == s[index-j])){
                return s;
            }
        } 
          
    }
    return "";
}

string optimizedFirstPalidrome(vector<string>& words){
    for(const string& s : words){
        size_t start = 0;
        size_t end = s.size() - 1;
        bool check = true;
        while(start < end){
            if(s[start] != s[end]){
                check = false;
                break;
            }
            start ++;
            end --;
        }
        if(check == true){
            return s;
        }
    }
    return "";
}

int main(){
    vector<string> words{"racecar"};
    cout <<  firstPalidrome(words) <<endl;
    return 0;
}
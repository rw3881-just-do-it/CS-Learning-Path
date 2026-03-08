/*find the length of the longest substring without duplicate characters

-sure, we can use a map
-or, we can use two pointers to create a sliding window, and a vector to 
keep track of unique characters in the substring - use ASCII support! - similar to a map
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string& s){
    int length = s.size();
    if(length == 0){
        return 0;
    }
    int res = 0;
    vector<bool> check(128, false);
    size_t left = 0;
    for(size_t right = 0; right < length; ++right){
        while(check[s[right]] == true){
            check[s[left]] = false;
            ++left;
        }
        check[s[right]] = true;
        if(right - left + 1 > res){
            res = right - left + 1;
        }
    }
    return res;
}

int main(){

}
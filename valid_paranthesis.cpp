/*valid paranthesis
-emphasize on the opposite pairs within sequences
-stack.pop() has no return, access value using stack.top()
-ASCII for () difference one, for [] and {} differences are two
-many edge cases: see comments*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2){ // [ f
            return false;
        }
        bool poped = false; // [[ f
        stack<char> saved;
        for (size_t i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                saved.push(s[i]);
            }
            else {
                if(saved.size() < 1){ // ]...f
                    return false;
                }
                poped = true; // [[ f
                char out;
                out = saved.top();
                saved.pop();
                if (s[i] == ')'){
                    if (out != s[i] - 1){return false;}
                }
                else{
                    if (out != s[i] - 2){return false;}
                }

            }
        }
        if (saved.size()<1){ //empty, all checked
            return poped;
        }
        return false; // [][][ f
    }
};

int main(){
    return 0;
}
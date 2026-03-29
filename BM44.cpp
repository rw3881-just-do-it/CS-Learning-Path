#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        }
    }
    
    return st.empty();
}

int main(){
    
}
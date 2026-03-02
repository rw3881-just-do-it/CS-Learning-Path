#include <iostream>
#include <string>
using namespace std;
//can use a nested loop, a hashtable - a frequency check,
//a pre-defined array for the bounded scenario could
//achieve O(n) runtime and O(1) space

int firstUniqChar(string& s){
    int freq[256] = {0};
    for (char c : s){
        freq[(unsigned char)c]++;
    }
    for (size_t i = 0; i < s.size(); ++i){
        if (freq[(unsigned char)s[i]] == 1){
            return i;
        }
    }
    return -1;
}

int main(){
    string s = "leetcode";
    cout << firstUniqChar(s) << endl;
}
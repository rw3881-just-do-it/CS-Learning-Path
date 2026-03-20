#include <iostream>
#include <vector>
using namespace std;

//two ways to find the longest continous substring
//-dp vector
//sliding window

string LCS(const string& str1, const string& str2){
    size_t m = str1.size();
    size_t n = str2.size();

    vector<int> dp(n + 1, 0);
    //track maximum length found so far
    int maxLen = 0;
    //track ending position in str1 where maxLen occurs
    int endPos = 0;

    for (size_t i = 1; i <= m; ++i){
        //iterate str2 backwards for space optimizing
        for (size_t j = n; j >= 1; --j){
            //compare str1[i] with str2[j]
            if (str1[i - 1] == str2[j - 1]){
                //dp[j] = length of common substring ending at str1[i - 1] and str2[j - 1]
                //dp[j - 1] computed in previous iteration for the length ending at str1[i - 2] and str2[j - 2]
                dp[j] = dp[j - 1] + 1;
                if (dp[j] > maxLen){
                    //update for longer length
                    maxLen = dp[j];
                    //record where in str1 this substring ENDS
                    endPos = i - 1;
                }
            }
            else{
                //don't match, length is 0
                dp[j] = 0;
            }
        }
    }
    if (maxLen == 0){
        return "-1";
    }
    return str1.substr(endPos - maxLen + 1, maxLen);
}

string SlidingWindowLCS(const string& str1, const string& str2) {
    size_t m = str1.size();
    size_t n = str2.size();
    
    int maxLen = 0;
    int endPos = 0;
    
    //scan all possible diagonals in the comparison matrix
    //a diagonal represents pairs (i, j) where (i - j) is constant
    //each diagonal is scanned continuously to find consecutive matches
    
    //scan diagonals starting from the first row (str1's perspective)
    //diagonals begin at (i, 0) where i ranges from 0 to m-1
    for (size_t i = 0; i < m; ++i) {
        size_t x = i; //current position in str1 (row index)
        size_t y = 0; //current position in str2 (column index)
        int currentLen = 0; //length of current consecutive matches on this diagonal
        
        //follow this diagonal until hit the boundary
        while (x < m && y < n) {
            if (str1[x] == str2[y]) {
                //characters match - extend the current substring
                currentLen++;
                //update global maximum if needed
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    endPos = x; //current position in str1 is the end
                }
            } else {
                //not match, reset
                currentLen = 0;
            }
            //move down and right diagonally
            ++x;
            ++y;
        }
    }
    
    //scan diagonals starting from the first column (str2's perspective)
    //diagonals begin at (0, j) where j ranges from 1 to n-1
    //skip j=0 because that diagonal was already covered in the previous loop (when i=0)
    for (size_t j = 1; j < n; ++j) {
        size_t x = 0; //position in str1 (row index)
        size_t y = j; //position in str2 (column index)
        int currentLen = 0; //length of current consecutive matches on this diagonal
        
        //follow this diagonal
        while (x < m && y < n) {
            if (str1[x] == str2[y]) {
                currentLen++;
                //update global maximum if needed
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    endPos = x;  //current position in str1 is the end
                }
            } else {
                currentLen = 0;
            }
            ++x;
            ++y;
        }
    }
    
    //if no common substring found
    if (maxLen == 0) {
        return "-1";
    }
    
    //extract and return the longest common substring
    return str1.substr(endPos - maxLen + 1, maxLen);
}

int main(){}
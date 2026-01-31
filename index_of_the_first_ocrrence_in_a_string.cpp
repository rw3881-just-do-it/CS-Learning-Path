/*return the index of the first occrence substring in a string*/
#include <iostream>
#include <string>
using namespace std;

/*
edge value for loops with index
    the outer loop that runs through the longer string:
        from 0 to lenh-lenn (include), since j < max(i+lenn) = lenh -lenn + lenn = lenh
        if i < lenh-lenn, then j < max(i+len) = lenh-lenn-1+lenn = lenh -1, which is incorrect
*/
class MySolution{
    public:
        int strStr(string haystack, string needle){
            size_t lenh = haystack.size();
            size_t lenn = needle.size();
            if (lenn > lenh){
                return -1;
            }
            bool same = true;
            for (size_t i = 0; i <= lenh-lenn; i++){
                if(haystack[i] == needle[0]){
                    for (size_t j = i + 1; j < i + lenn; j++){
                        if(haystack[j] != needle[j-i]){
                            same = false;
                            break;
                        }
                    }
                    if(same ==  true){
                        return i;
                    }
                    else{
                        same = true;
                    }
                }
            }
            return -1;

        }
};

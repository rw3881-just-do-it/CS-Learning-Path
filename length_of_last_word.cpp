/*length of the last word in a given string
*/
/*size_t i means i >= 0 will always be true, and the loop would never stop if using i>=0 for the condition.
so size_t is not a proper type here.
Sterling will be so mad but we have to use int to represent index in this case.

what will happen if size_t i = 0, and then we do i--?
i will be 18446744073709551615, the maximum value of an unsigned 64-bit integer.
this assignment will not cause a memory overflow, 
but s[i] will cause a memory overflow since we use i as an index*/

#include <iostream>
#include <string>

using namespace std;

class MySolution{
public:
    int lengthOfLastword(string s){
        if (s.size()<1){
            return 0;
        }
        if (s.size() == 1){
            return 1;
        }
        int len = s.size()-1;
        while (s[len] == ' ' && len >= 0) //prevent edge case "     "
        {
            len --;
        }
        if (len < 0){
            return 0;
        }
        for (int i = len; i >= 0; i--){ //the size_t part
            if(s[i] == ' '){
                return (len - i);
            }
        }
        return len+1;
    }

};


int main(){
    return 0;
}
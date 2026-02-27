/*reverse the string in place

-intuitive: use a loop from front to middle

*/
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s){
    size_t index = s.size();
    for(size_t i = 0; i < s.size()/2; ++i){
        char temp = s[i];
        s[i] = s[index - 1 - i];
        s[index - 1 - i] = temp;
    }
}
int main(){
    vector<char> s = {'h','e','l','l','o','e'};
    reverseString(s);
    for (size_t i = 0; i < s.size(); ++i){
        cout << s[i] << endl;
    }
}
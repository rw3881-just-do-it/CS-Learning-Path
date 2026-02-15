/*get a column number and convert it into deximal int

-reversion of excel sheet column
-pass by const reference to save space
-string can be randomly accessed!
-plus one to mend the gap between 1 - 26 and 0 - 25
*/
#include <iostream>
#include <string>
using namespace std;
// 'A' = 65
int titleToNumber(const string& columnTitle){
    int res = 0;
    for (size_t i = 0; i < columnTitle.size(); i ++){
        res = res * 26 + int(columnTitle[i] - 65) + 1;
    }
    return res;
}

int main(){
    string s = "A";
    int res = titleToNumber(s);
    cout << res;
    return 0;
}
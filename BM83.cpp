#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string covert(string& a){
    string res = "";
    stack<string> reverse;
    for (size_t i = 0; i < a.size(); ++i){
        if (a[i] >='A' && a[i] <='Z'){
            res += a[i] + 32;
        }
        else if(a[i] >='a' && a[i] <='z'){
            res += a[i] - 32;
        }
        else{
            reverse.push(res);
            reverse.push(" ");
            res = "";
        }
    }
    while (reverse.empty() != true){
        string temp = reverse.top();
        reverse.pop();
        res += temp;
    }
    return res;
}

int main(){
    string a = "Hello World";
    string res = covert(a);
    cout << res;
    return 0;
}
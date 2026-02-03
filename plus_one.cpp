/*plus one
manipulation on int vector
not too much to say*/
#include <iostream>
#include <vector>
using namespace std;


vector<int> plusone(vector<int>& digits){
    if(digits[digits.size()-1] + 1 <= 9){
        digits[digits.size()-1] += 1;
        return digits;
    }
    else{
        digits[digits.size()-1] = 0;
        int index = digits.size() - 2;
        while (index >= 0){
            if(digits[index] + 1 <= 9){
                digits[index] += 1;
                return digits;
            }
            else{
                digits[index] = 0;
                index --;
            }
        }
        vector<int> res;
        res.push_back(1);
        for (int i = 0; i < digits.size(); i++){
            res.push_back(digits[i]);
        }
        return res;
    }
}

int main(){
    vector<int> intv;
    intv.push_back(9);
    intv.push_back(9);
    intv.push_back(9);
    vector<int> res;
    res = plusone(intv);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
given a string that contains numbers,
return the number of possible solutions for converting 
the numbers into letters. 
conversion rule: a -> 1, b -> 2... z -> 26

another form of climbing stairs with limitations on the current number
and the previous one
*/

int solve (string nums){
    if (nums == "0"){
        return 0;
    }
    size_t n = nums.size();
    vector<int> res(n, 0);
    res[0] = 1; 
    for (size_t i = 1; i < nums.size(); ++i){
        if (nums[i] != '0'){
            res[i] = res[i - 1];
        }
        if((nums[i] <= '6' && nums[i - 1] == '2') || (nums[i - 1] == '1')){//number from 10 - 26.
            if (i >= 2){
                res[i] += res[i - 2];
            }else{
                res[i] += res[i - 1];
            }
        }
    }
    return res[n - 1];
}

int main(){
    cout << solve("31717126241541717");
}
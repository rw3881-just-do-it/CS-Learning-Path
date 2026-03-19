//for the ith room, there are two options
//-steal: then the i-1 th room can not be stolen,
//  thus the max_curr_money = max(i-2) th room + curr
//-not steal:
//  thus the max_curr_money = max(i-1)th room

//reflection: the mindset feels like BM3
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums){
    if (nums.size() == 0){
        return 0;
    }
    if (nums.size() == 1){
        return nums[0];
    }
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int curr = prev1;
    for (size_t i = 2; i < nums.size(); ++i){
        curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(){}
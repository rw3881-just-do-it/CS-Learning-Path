/*
Solution to 1. Two Sum using vectors, with time complexity O(n^2)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++){
            for (size_t j = i + 1; j < nums.size(); j++){ // start from i+1
                if (nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};
int main(){
    return 0;
}
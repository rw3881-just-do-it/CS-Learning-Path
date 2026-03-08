/*
return the third distinct max number,
if the thrid maximum does not exsit, return the maximum

-intuition: make them in order and return - runtime nlogn
-loop through the vector and check using pointers!
*/
#include <iostream>
#include <vector>
using namespace std;
int thirdMax (vector<int>& nums){
    //since we use pointers, then order matters (see inside the loop)
    int* max1 = nullptr;
    int* max2 = nullptr;
    int* max3 = nullptr;
    for (size_t i = 0; i < nums.size(); ++i){
        //check each pointer first to avoid segmentation error
        //must be up here or the repeated test fails
        if(max1 && nums[i] == *max1 || max2 && nums[i] == *max2 || max3 && nums[i] == *max3){
            continue;
        }
        //must judge nullptr first, or segmentation error in the first loop
        if(max1 == nullptr || nums[i]>*max1){
            max3 = max2;
            max2 = max1;
            max1 = &nums[i];
        }else if(max2 == nullptr || nums[i]>*max2){
            max3 = max2;
            max2 = &nums[i];
        }else if(max3 == nullptr || nums[i]>*max3){
            max3 = &nums[i];
        }
    }
    if (max3 != nullptr){
        return *max3;
    }
    return *max1;
}
int main(){
    vector<int> v = {3,2,1};
    cout << thirdMax(v);
}
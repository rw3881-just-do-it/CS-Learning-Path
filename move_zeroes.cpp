/*put all the zeros in the given list to the back

-intuition: move elements forward
-the most efficient way is to move all the non-zero forward and
keep track of the position of the last zero and all set*/
#include <iostream>
#include <vector>
using namespace std;

vector<int>& moveZeroes(vector<int>& nums){
    int pos = 0;
    for (size_t i = 0; i < nums.size(); i++){
        if (nums[i] != 0){
            nums[pos] = nums[i];
            pos ++;
        }
    }
    while(pos < nums.size()){
        nums[pos] = 0;
        pos ++;
    }
    return nums;
}

int main(){
    vector<int> nums = {0, 2, 1, 0, 13, 5};
    moveZeroes(nums);
    for (size_t i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}
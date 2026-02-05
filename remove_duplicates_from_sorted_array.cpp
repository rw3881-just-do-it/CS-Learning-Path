/*remove duplicates from sorted array
-be careful about the test condition, and then deal with the index
-did a bit of opitimization of memory usage: using i to avoid replicate nums.size()
-the judgement way inspired by remove_element second solution
*/
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int index = 0;
    size_t i = 0; //memory optimization
    for(i = 0; i < nums.size() - 1; i++){
        if(nums[i] != nums[i+1]){
            nums[index] = nums[i];
            index ++;
        }
    }
        if (index == 0){
        index ++;
    }
    if (nums[i] != nums[index-1]){
        nums[index] = nums[nums.size()-1];
                index++;
                
    }
    // i == nums.size() -1 
    if(i + 1 == 1){
        return 1;
    }
    return index;
}

void display(int res, vector<int>& vec){
    for (size_t i = 0; i < res; i ++){
        //cout << "start" << endl;
        cout << vec[i] << endl;
    }
}

int main(){
    vector<int> test;
    test.push_back(1);
    //test.push_back(1);
    test.push_back(2);
    int res = removeDuplicates(test);
    cout << "res"<<res << endl;
    display(res, test);
    return 0;
}
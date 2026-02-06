/*search_insert_position
-loop through a sorted list to find the target. if the target exists then return
its index, or return the index it should be inserted

-return low instead of mid would avoid edge cases[<target]low[>target]

second solution:
-find where the value should be, no need to think about comparing the value
since it is sorted, then we just inherit the idea of binary search
for the proper index*/

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;                  
        }
        else if (nums[mid] < target) {
            low = mid + 1;               
        }
        else {
            high = mid - 1;              
        }
    }

    return low; 
}

int SecondsearchInsert(vector<int>& nums, int target){
    size_t high = nums.size();
    size_t low = 0;
    while(low < high){
        int mid = (high + low) / 2;
        if(nums[mid] < target){
            low  = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return low;

}

int main(){
    vector<int> intv;
    for (int i = 0; i < 11; i++){
        intv.push_back(i);
    }
    int res = 0;
    res = searchInsert(intv, -1);
    cout << res;

    return 0;
}
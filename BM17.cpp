#include<iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Calculate mid to avoid integer overflow
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // Found target, return index
            }
            else if (nums[mid] < target) {
                left = mid + 1;  // Target is in right half
            }
            else {
                right = mid - 1;  // Target is in left half
            }
        }
        
        return -1;  // Target not found
}


int search(vector<int>& nums, int target) {
    return SecondBinarySearch(nums, target, 0, nums.size() - 1);
}
int SecondBinarySearch(vector<int>& nums, int target, int left, int right){
    if (left > right) {
            return -1;  // Base case: target not found
    }
        
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return SecondBinarySearch(nums, target, mid + 1, right);
        }
        else {
            return SecondBinarySearch(nums, target, left, mid - 1);
        }
}
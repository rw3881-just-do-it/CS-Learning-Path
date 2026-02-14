/* find the majority element in a given vector
majority is defined as appeared at least more than floor(n/2) times

four intuitive solutions with two clearly stated and explained
*/
#include <iostream>
#include <vector>
using namespace std;

/*
-hash table will do it
-sort and return the middle one
-moore voting algorithm - using increament and decreament to indicate majority enhancement
or decreament
-bit manipulation - AND (check a bit) and OR (set a bit) gates - O(32n) time complexity
*/

//moore voting algorithm
int majorityElement(vector<int>& nums){
    int count = 1;
    int majority = nums[0];
    for (size_t i = 1; i < nums.size(); i++){
        if(count == 0){
            majority  = nums[i];
            count ++;
        }
        else{
            if(majority == nums[i]){
                count ++;
            }
            else{
                count --;
            }
        }
    }
    return majority;
}

//bit manipulation solution
//for each position, which bit (0 or 1) appears most often
//converting the numbers into binary, and based on each bit,
//count how many numbers have that bit set
//if count > n/2, set that bit in the answer
int secondMajorityElement(vector<int>& nums){
    int res = 0;
    int n = nums.size();
    //checks all 32 bits of an int, one bit at a time
    for (int i = 0; i < 32; i++){
        int bitCount = 0;
        for(int num : nums){
            // AND logic gate with creating a bit mask that only the i-th bit set to 1
            if(num & (1 << i)){ //checks is the i-th bit of num equal to 1
                bitCount ++; // count how many numbers have the i-th bit set to 1
            }
        }
        if(bitCount > n/2){ // if more than half of the numbers have this bit set,
                            //then the majority element must also have this bit set
            // OR logic gate
            res |= (1 << i); // sets the i-th bit of res to 1
        }
    }
    return res;
}

int main(){
    return 0;
}
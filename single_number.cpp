#include <iostream>
/*find the number that only appears once in the given vector
linear time and constant memory usage.

three potential solutions: 
-hash table - not constant space
-sorted and then compare - not linear time
-bitwise xor operator
*/
#include <vector>
#include <algorithm>
using namespace std;

//use sort(nums.begin(), nums.end()) with #include <algorithm>
int singleNumber(vector<int>& nums){
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i += 2){
        if(nums[i] != nums[i+1]){
            return nums[i];
        }
    }
    return nums[nums.size()-1];
}

/*
use bitwise XOR (^)
first transfer the numbers into binary
^ operator compares each bit at the same postion, and the bit will be set 1
if the corresponding bits differ.
7^4 = 3 because:
 111
^100
=011 = 3

^ is not order sensitive, it supports commutative and associative properties,
and a^a = 0, b^0 = b

So the elements with frecency 2 will result in 0 (because no difference),
and the only element with frequency 1 will last for the answer!
*/
int secondSingleNumber(vector<int>& nums){
    int res = 0;
    for(int x : nums){
        res^=x;
    }
    return res;
}

int main(){
    return 0;
}
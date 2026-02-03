/*remove element-no need to care about the order
take care of the index starting from the front, swap all the target value to the back.
-logic: if/else is enough. binary scenario no need for else if
-index so need to handle overflow, especially with index--,
the while loop must have another condition index > 0
-use a fast pointer/index and a slow pointer/index from the front
to overwrite the content is the best solution
fast, safe, save space--see the second solution*/
#include <iostream>
#include <vector>
using namespace std;

//first solution
int removeElement(vector<int>& nums, int val){
    int front = 0;
    int back = nums.size() - 1;
    if(back < 0){return 0;}
    if(back ==  0){
        if(nums[0] != val){
            return 1;
        }
        else{
            nums.pop_back();
            return 0;
        }
    }
    while (front <= back && back > 0){
        if(nums[front] == val){
            if(nums[back] != val){
                nums[front] = nums[back];
                nums[back] = val;
                front ++;
                back --;
            }
            else{//back == val
                back --;
            }
        }
        else{ //front != val
            if(nums[back] != val){
                front ++;
            }
            else{ //back == val
                front ++;
                back --;
            }
        }
    }
    if(back == nums.size() - 1){
        return back + 1;
    }
    for (size_t i = nums.size() - 1; i > back; i--){
        nums.pop_back();
    }
    if(nums[back] == val){
        nums.pop_back();
        return back;
    }
    return back + 1;
}

//second solution
//amazingly uses the benefit of the testing method
//overwrites the content with a fast index and a slow index
int shorterRemoveElem(vector<int>& nums, int val){
    int index = 0;
    for (size_t i = 0; i < nums.size(); i++){
        if(nums[i] != val){
            nums[index] = nums[i];
            index ++; //same function as the first pointer
        }
    }
    return index;
}

int main(){
    return 0;
}
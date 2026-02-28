/*return an array that contains the intersection of two arrays

-intuition: nested loop to find over, with a helper function
that checks whether the added number already exists in the result
    -cost too much time
-second solution: sort two arrays, then use two pointers
-or, hash set
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    size_t i = 0;
    size_t j = 0;
    while (i < nums1.size() && j < nums2.size()){ //must be &&
        //because once one reaches the end, there would be outrange happen!
        if(nums1[i] == nums2[j]){
            if(res.size() == 0){
                res.push_back(nums1[i]);
            }
            else {
                if (res[res.size()-1] != nums1[i]){
                    res.push_back(nums1[i]);
                }
            }
            ++i;
            ++j;
        } else if(nums1[i] < nums2[j]){
            ++i;
        }
        else{
            ++j;
        }
    }
    return res;
}

int main(){
    vector<int> s1 = {4,9,5};
    vector<int> s2 = {9,4,9,8,4};
    vector<int> res = intersection(s1, s2);
    for (size_t i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
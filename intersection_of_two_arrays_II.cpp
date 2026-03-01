/*return an array that contains the intersection of two arrays,
keep the repeated elements as the number of time it appeared in the
intersection

-same logic as intersection_of_two_arrays without a check in the loop
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
            res.push_back(nums1[i]);
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
    vector<int> s1 = {1,2,2,1};
    vector<int> s2 = {2,2};
    vector<int> res = intersection(s1, s2);
    for (size_t i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
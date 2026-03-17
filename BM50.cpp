#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//hash map
vector<int> twoSum(vector<int>& numbers, int target) {
    // Create a hash map to store the value and its index
    unordered_map<int, int> numMap;
    
    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];
        
        // Check if the complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            // Return indices in ascending order (1-based)
            return {numMap[complement] + 1, i + 1};
        }
        
        // Store the current number and its index
        numMap[numbers[i]] = i;
    }
    
    // Since the problem guarantees a solution exists, we'll never reach here
    return {};
}

//sorted and pointers
vector<int> twoSum(vector<int>& numbers, int target) {
    // Create a vector of pairs to store original indices
    vector<pair<int, int>> numsWithIndex;
    for (int i = 0; i < numbers.size(); i++) {
        numsWithIndex.push_back({numbers[i], i});
    }
    
    // Sort based on values (O(n log n))
    sort(numsWithIndex.begin(), numsWithIndex.end());
    
    // Two-pointer approach
    int left = 0;
    int right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numsWithIndex[left].first + numsWithIndex[right].first;
        
        if (sum == target) {
            // Get original indices and sort them
            int idx1 = numsWithIndex[left].second + 1;
            int idx2 = numsWithIndex[right].second + 1;
            if (idx1 < idx2) {
                return {idx1, idx2};
            } else {
                return {idx2, idx1};
            }
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}
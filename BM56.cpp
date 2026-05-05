/*need to deal with duplicate numbers*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& num, vector<bool>& used, vector<int>& current) {
        // Base case: complete permutation
        if (current.size() == num.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            // Skip if this number is already used
            if (used[i]) continue;
            
            // Skip duplicates
            // If current number equals previous number AND previous wasn't used
            // then we would generate the same permutation as before
            if (i > 0 && num[i] == num[i-1] && !used[i-1]) continue;
            
            // Choose
            used[i] = true;
            current.push_back(num[i]);
            
            // Explore (smaller case)
            backtrack(num, used, current);
            
            // Unchoose (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        result.clear();
        if (num.empty()) return result;
        
        // Sort so duplicates are adjacent
        sort(num.begin(), num.end());
        
        vector<bool> used(num.size(), false);
        vector<int> current;
        
        backtrack(num, used, current);
        return result;
    }
};
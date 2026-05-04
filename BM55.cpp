/*
base case: when the current permutation's length
    equals the input array's length
smaller case:
    problem size: number of unchosen (remaining) elements
    smaller case: after fixing one element at current position.
        recursively permute the remaining n-1 elements
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    
    void generate(vector<int>& num, int start) {
        // Base case: we've swapped all positions
        if (start == num.size() - 1) {
            result.push_back(num);
            return;
        }
        
        // Try placing each remaining element at position 'start'
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);           // Choose
            generate(num, start + 1);           // Explore
            swap(num[start], num[i]);           // Unchoose (backtrack)
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& num) {
        result.clear();
        generate(num, 0);
        return result;
    }
};
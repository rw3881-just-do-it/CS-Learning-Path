#include <iostream>
#include <vector>

using namespace std;
int FindGreatestSumOfSubArray(vector<int>& array) {
    int n = array.size();
    if (n == 0) return 0;
    
    int currentSum = array[0];
    int maxSum = array[0];
    
    for (int i = 1; i < n; i++) {
        // Either start a new subarray at i, or extend the previous subarray
        currentSum = max(array[i], currentSum + array[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(){}
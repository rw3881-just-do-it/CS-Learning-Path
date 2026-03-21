#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//dp: dp[i][j] = dp[i - 1][j] + dp[i][j - 1] because we can only come from above or left
//the prob is equivalent to choosing positions for down moves (or right moves) among total moves - C
//need to take care of the potential overflow

int DPuniquePaths(int m, int n){
    vector<int> dp(n, 1);
    for (size_t i = 1; i < m; ++i){
        for (size_t j = 1; j < n; ++j){
            //dp[j] before update = ways to reach cell above from previous row
            //dp[j - 1] = ways to reach cell on the left
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[n - 1];
}

//to go from (0,0) to (m - 1, n - 1), we need exactly (m - 1) down moves and (n - 1) right moves
//total moves = m - 1 + n - 1 = m + n - 2
//choose which positions among the total moves will be down moves,
//so C(m + n - 2, m - 1) or C(m + n - 2, n - 1), they are the same
int MathUniquePaths(int m, int n){
    long long res = 1; //overflow issue!
    int k = min(m - 1, n - 1); // to optimize
    int total = m + n - 2;
    for (int i = 1; i <= k; ++i){
        res = res * (total - k + i)/i;
    }
    return res;
}
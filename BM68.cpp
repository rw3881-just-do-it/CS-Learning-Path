#include <iostream>
#include <vector>
using namespace std;

//the minimum path sum to reach any cell depends only on the minimum
//sums of the cell above and the cell to the left, plus the current cell's value

int minPathSum(vector<vector<int>>& matrix){
   size_t n = matrix.size();
   size_t m = matrix[0].size();
   
   //one row to store current state
   vector<int> dp(m, 0);
   dp[0] = matrix[0][0];

   //fill first row
   for (size_t j = 1; j < m; ++j){
    dp[j] = dp[j - 1] + matrix[0][j];
   }
   //process remaining rows
   for (size_t i = 1; i < n; ++i){
    //first column - can only come from above
    dp[0] = dp[0] + matrix[i][0];

    //remaining - min(from_above, from_left) + current value
    for (size_t j = 1; j < m; ++j){
        dp[j] = min(dp[j], dp[j - 1]) + matrix[i][j];
    }
   }
   return dp[m - 1];
}

//in-place dp, space optimized
//modify the original matrix in place
int OptminPathSum(vector<vector<int>>& matrix){
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    
    //fill first row
    for (size_t j = 1; j < m; ++j){
        matrix[0][j] += matrix[0][j - 1];
    }
    //fill first colum
    for (size_t i = 1; i < n; ++i){
        matrix[i][0] += matrix[i - 1][0];
    }
    for (size_t i = 1; i < n; ++i){
        for (size_t j = 1; j < m; ++j){
            matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    return matrix[n - 1][m - 1];
}

int main(){}
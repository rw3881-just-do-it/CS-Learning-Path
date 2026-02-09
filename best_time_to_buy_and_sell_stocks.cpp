/*best_time_to_buy_and_sell_stocks
return the maximum profit based on the buying price given.

reflection:
-good: get the idea and came up with a vague idea of the technique used
-bad: did not consider the logic clearly. practice more! i can do it!
*/
#include <iostream>
#include <vector>

using namespace std;

//the very intuitive idea.
//this works, but time complexity too bad, n^2
//so this can not handle large amount of numbers...
int maxProfit(vector<int>& prices){
    int profit = 0;
    for (size_t i = 0; i < prices.size(); i++){
        for (size_t j = i + 1; j < prices.size(); j++){
            if (prices[j] - prices[i] > profit){
                profit = prices[j] - prices[i];
            }
        }
    }
    return profit;
}

//obviously, think about sliding window.
//the profit is not related to the current smallest value,
//so handle the profit separate from the smallest value!
int secondMaxProfit(vector<int>& prices){
    int profit = 0;
    size_t cheap = 0;
    for (size_t i = 1; i < prices.size(); i ++){
        if(prices[i] < prices[cheap]){
            cheap = i;
        }
        else{
            if(prices[i] - prices[cheap] > profit){
                profit = prices[i] - prices[cheap];
            }
        }
    }
    return profit;
}


int main(){
    vector<int> prices{7,1,5,3,6,4};
    int res = secondMaxProfit(prices);
    cout << res << endl;
    return 0;
}
/*
given an int vector. cost[i] is the cost to climb the ith stair, i start with 0.
if you pay, you can choose to climb one or two stairs.
you can choose from index 0 or 1 to start to climb.
return the min cost to reach the end of the stairs.

-it is a prefix question, since the final result depend on the previous choice
(and due to the same reason, it is NOT a sliding window quesion)
*/
#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost){
    int first = 0; //first step
    int second = 0; //second step
    //the last step is free, but we still need to get onto that step, so <=
    for (size_t i = 2; i <= cost.size(); ++i){ 
        int curr = min(second + cost[i - 1], first + cost[i - 2]);
        //second + cost[i-1]: the cost to arrive on ith step by having taken one step
        //first + cost[i-2]: the cost to arrive on ith step by taken two steps
        first = second;
        second = curr;
    }
    return second;
}

int main(){
    vector<int> v = {2, 5, 20};
    cout << minCostClimbingStairs(v);
}
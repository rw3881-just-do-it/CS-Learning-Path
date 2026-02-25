/*given an integer, return a vector that contains number of 1s inside
that integer

-intuition - easy, helper function and one by one

-faster method: store and reuse the result, a recursive thought*/
#include <iostream>
#include <vector>
using namespace std;

int numberBits(int n){
    int count = 0;
    while (n != 0){
        if (n & 1){
            count += 1;
        }
        n = n / 2;
    }
    return count;
}

vector<int> countBits(int n){
    vector<int> res;
    for (int i = 0; i < n + 1; ++i){
        res.emplace_back(numberBits(i));
    }
    return res;
}

//second method
vector<int> secondCountBits(int n){
    vector<int> res(n+1, 0);//initialize, because we know when n = 0, the result should be 0
    for (size_t i = 1; i <= n ; ++i){
        res[i] = res[i/2] + (i & 1);
    }
    return res;
}

int main(){
    vector<int> res = secondCountBits(2);
    for (size_t i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
// call a pre-defined int guess(int num) that returns
//-1 if guess is higher than the number picked
// 1 if guess is lower than the number picked
// 0 just right

//-intuition: binary search

int guessNumber(int n){
    int low = 1;
    int high = n;
    while(low <= high){ //must allow equal, could be even
        int mid = low + (high - low)/2;
        int res = guess(mid);
        if(res == 0){
            return mid;
        }
        else if(res == 1){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    
}
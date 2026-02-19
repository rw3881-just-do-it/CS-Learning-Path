/*
find the first bad version from a series of versions.
a bit hard to test locally since an API isBadVersion is implicitly provided

-intuition: check it from back to find the first false and return n + 1
-second solution: binary search, with condition low <= high, and be careful about the mid,
which should be mid = low + (high - low)/2
*/

/*
sample of the test case, where number is the version number
1 2 3 4 5 6 7 8 9 10
F F F F F F F T T T
mid = 5 f low = 6
mid = 6 + 2 = 8 t high = 7
mid = 6 f low = 7
*/

#include <iostream>
using namespace std;
bool isBadVersion(int version){}
bool isBadVersion(int version){}// an API already defined, return true if the verion is bad
int firstBadVersion(int n){
    while (isBadVersion(n) == true){
        n--;
    }
    return n+1;
}

int BinarySearchfirstBadVersion(int n){
    int low = 0;
    int high = n;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (isBadVersion(mid) == true){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return high+1;
}

int main(){

}
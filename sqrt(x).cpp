/*sqrt(x)
find the square root without calling build-in functions
-mySqrt: my first idea, intuitive but slow
-mySecondSqrt: my second idea, using binary search

-binary search: "distance";
in this case, the distance is not normally distributed as usual since it is root instead of 2 times,
so we go to the core understanding of "distance":
measure the distance (high - start) and then move halfway from start,
to get mid = start + (high-start)/2. VERY IMPORTANT!
-the reason we used (high+low)/2 in some cases is because they are bounded,
and (high + low)/2 is equal to low + (high - low)/2!
*/
#include <iostream>
using namespace std;

int mySqrt(int x){
    long i = 0; // or i*i might out of the range of int
    while((i <= x/2) && i*i < x){
        i ++;
    }
    if (i*i == x){
        return i;
    }
    else{
        return i - 1;
    }
}

int mySecondSqrt(int x){
    int start = 1;
    long mid = 0;
    int high = x;
    while (start <= high){
        mid = start + (high - start)/2;
        if (mid*mid < x){
            start = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if (start*start == x){
        return start;
    }
    return start-1;

}


int main(){
    int res = mySecondSqrt(1);
    cout << res;
    return 0;
}

/*
1 - 0
-1
2 - 1
3 - 1
2
4 - 2
5 - 2
6 - 2
7
8
-5
9 - 3
...
-6
16 - 4
*/
/*nth Fibonacci number
*/
//time complexity: O(n)
#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int n){
        if (n == 1 || n == 2){
            return 1;
        }
        int prev = 1;
        int next = 1;
        int curr = 0;
        for (int i = 3; i <= n; ++i){
            curr = prev + next;
            prev = next;
            next = curr;
        }
        return curr;
}
/*
f(2k) = f(k)*2(2*f(k+1) - f(k))
f(2k + 1) = f(k)^2 + f(k+1)^2
*/

pair<int, int> fast_doubling(int n){
    if (n == 0){
        return {0, 1};
    }
    auto [a, b] = fast_doubling(n/2); //a = f(k), b = f(k+1)
    int c = a*(2*b - a);
    int d = a*a + b*b;
    if(n%2 == 0){
        return {c,d};
    }
    else{
        return {d, c+d};
    }
}
int fasterFibonacci(int n){
    pair<int, int> fast_doubling(int n){
    if (n == 0){
        return {0, 1};
    }
    auto [a, b] = fast_doubling(n/2); //a = f(k), b = f(k+1)
    int c = a*(2*b - a);
    int d = a*a + b*b;
    if(n%2 == 0){
        return {c,d};
    }
    else{
        return {d, c+d};
    }
}
}

int main(){
    cout << fasterFibonacci(4);
}
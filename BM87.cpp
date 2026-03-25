#include <iostream>
#include <vector>
#include <array>
using namespace std;

//do the merge from back to front

void merge(int A[], int m, int B[], int n){
    // Pointers for last element
    int i = m - 1; 
    int j = n - 1;
    // Pointer for last position in merged array
    int k = m + n - 1;  
    
    // Compare elements from the end and place the larger one at position k
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[k--] = A[i--];  // Take from A
        } else {
            A[k--] = B[j--];  // Take from B
        }
    }
    
    // If there are remaining elements in B, copy them
    // (If there are remaining elements in A, they're already in place)
    while (j >= 0) {
        A[k--] = B[j--];
    }
}

int main(){

}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return true;
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());
    // Check if valid difference
    if ((mx - mn) % (n - 1) != 0) return false;
    int d = (mx - mn) / (n - 1);
    // Special case: all elements must be equal
    if (d == 0) {
        for (int x : arr) {
            if (x != mn) return false;
        }
        return true;
    }
    // Place elements in correct positions
    for (int i = 0; i < n; i++) {
    while (arr[i] != mn + i * d) {
        int idx = (arr[i] - mn) / d;
        // Check validity
        if ((arr[i] - mn) % d != 0 || idx < 0 || idx >= n) return false;
        // Duplicate check
        if (arr[i] == arr[idx]) return false;
        // Swap into correct position
        swap(arr[i], arr[idx]);
        }
    }
    return true;
}
int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(1);
    cout << canMakeArithmeticProgression(arr);

}
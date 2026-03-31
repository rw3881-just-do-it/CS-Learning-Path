#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& numbers) {
    //Find candidate
    int candidate = 0;
    int count = 0;
    
    for (int num : numbers) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    //Verify candidate (not strictly needed if majority guaranteed)
    count = 0;
    for (int num : numbers) {
        if (num == candidate) {
            count++;
        }
    }
    
    if (count > numbers.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority (though problem says one exists)
    }
}

int main(){}
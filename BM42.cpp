#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    void push(int node) {
        // Simply push new elements onto stack1
        stack1.push(node);
    }

    int pop() {
        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        // The top of stack2 is the oldest element (front of queue)
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;  // Used for push operations
    stack<int> stack2;  // Used for pop operations
};
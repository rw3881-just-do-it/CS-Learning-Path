#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//iterative way
ListNode* ReverseList(ListNode* head){
    ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  // Store next
            curr->next = prev;   // Reverse link
            prev = curr;         // Move prev
            curr = next;         // Move curr
        }
        return prev;
}

//recurisve
ListNode* SecondReverseList(ListNode* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // Recursively reverse the rest of the list
    ListNode* newHead = SecondReverseList(head->next);
    // Reverse the current node's link
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

//using stack
ListNode* ThirdReverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    stack<ListNode*> nodeStack;
    ListNode* curr = head;
    // Push all nodes onto stack
    while (curr != nullptr) {
        nodeStack.push(curr);
        curr = curr->next;
    }
    // Pop and rebuild the list in reverse order
    ListNode* newHead = nodeStack.top();
    nodeStack.pop();
    curr = newHead;
    while (!nodeStack.empty()) {
        curr->next = nodeStack.top();
        nodeStack.pop();
        curr = curr->next;
    }
    curr->next = nullptr;  // Set the last node's next to nullptr
    return newHead;
}
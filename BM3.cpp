/*
given a linkedList, reverse the node grouped by k, and return the reversed list
*/
#include <iostream>
using namespace std;
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        // Create a dummy node to simplify handling of the new head
        ListNode* dummy = new ListNode{0};
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;  // End of the previous reversed group
        ListNode* curr = head;           // Current node to process

        while (curr) {
            //Check if there are at least k nodes left
            ListNode* check = curr;
            int count = 0;
            while (check && count < k) {
                check = check->next;
                count++;
            }

            if (count < k) {
                // Not enough nodes, leave remaining as is
                break;
            }

            //Reverse k nodes
            ListNode* groupStart = curr;
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;

            for (int i = 0; i < k; i++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect the reversed group with the rest of the list
            // prev is now the new head of the reversed group
            // groupStart is now the tail of the reversed group
            prevGroupEnd->next = prev;      // Connect previous group end to new group head
            groupStart->next = curr;         // Connect group tail to next segment
            prevGroupEnd = groupStart;       // Move prevGroupEnd to the end of this group
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
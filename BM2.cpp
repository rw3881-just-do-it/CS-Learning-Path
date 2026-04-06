/**
 * reverse a singular linked list based on a given interval
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n){
            return head;
        }
        ListNode* helper = new ListNode(0);
        helper->next = head;
        //find the node before position m
        ListNode* prev = helper;
        for (size_t i = 1; i < m; ++i){
            prev = prev ->next;
        }
        //reverse from m to n
        //prev is the node before the reversal start
        //start is the first node of the sublist to reverse
        ListNode* start = prev->next;
        ListNode* after = start->next;
        //reverse
        for(size_t i = 0; i < n - m; ++i){
            start-> next = after -> next;
            after -> next = prev -> next;
            prev -> next = after;
            after = start-> next;
        }
        ListNode* res = helper->next;
        delete helper;
        return res;
    }
};
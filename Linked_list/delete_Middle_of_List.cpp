//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include<iostream>
using namespace std;
#include"List.h"
class Solution {
private:
    ListNode * middleNode(ListNode *&head){
        ListNode * slow = head;
        ListNode *fast = head->next->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr)return nullptr;
        ListNode *mid = middleNode(head);
        mid ->next = mid->next->next;
        return head;
    }
};
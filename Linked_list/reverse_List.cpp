#include<iostream>
using namespace std;
#include"List.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};
int main(){
       
}
#include<iostream>
#include<List.h>
using namespace std;


class Solution {
    private:
    ListNode * middleNode(ListNode *&head){
        ListNode * slow = head;
        ListNode *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
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
public:
    void reorderList(ListNode* &head) {
        if(head == NULL || head->next == NULL)return;
        ListNode * mid = middleNode(head);
        ListNode * hs = reverseList(mid);
        ListNode * hf = head;
        // rearrange
        while (hf != NULL&& hs != nullptr)
        {
           ListNode *temp = hf->next;
           hf->next = hs;
           hf = temp;

           temp = hs->next ;
           hs->next  = hf;
           hs = temp;
        }

        // next of tail to null
        if(hf != nullptr){
            hf->next = nullptr;
        }  
    }
};
int main(){

}
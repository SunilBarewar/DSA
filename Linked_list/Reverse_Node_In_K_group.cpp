#include<iostream>
#include<List.h>
using namespace std;
class Solution {
    private:
    int listLen(ListNode * &head){
        ListNode * temp = head;
        int len = 0;
        while (temp != nullptr)
        {
            len++;
            temp = temp ->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)return head;
    int len = listLen(head);
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
        ListNode * prev = dummy,*curr = dummy, *nex = dummy;
        while(len >= k){
            curr = prev->next;
            nex = curr->next;
            for(int i = 1; i < k ;i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len-=k;
        }
        return dummy->next;
    }
};
int main(){

}
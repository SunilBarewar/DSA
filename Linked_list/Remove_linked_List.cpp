#include<bits/stdc++.h>
using namespace std;
#include "List.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)return head;
        ListNode * temp = head;
        ListNode * prev ;
        while(temp){
            if(head->val == val){
                head = head->next;
                temp = temp->next;
            }else if(temp ->next == NULL && temp->val ==val){
            prev ->next = NULL;
                temp = temp->next;
             }
            else if( temp->val == val) {
                prev ->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main(){
    
}
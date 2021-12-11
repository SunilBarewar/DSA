#include<iostream>
using namespace std;
#include<List.h>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(left == right)return head;
        ListNode * curr = head;
        ListNode * prev = NULL;
        for(int i = 0; curr && i < left-1;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode * last = prev;
        ListNode * newEnd = curr;
        ListNode * next;
        for(int  i = 0; curr && i < right -left +1;i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        newEnd->next  = curr;
        if(last){
            last->next = prev;
        }else{
            head = prev;
        }
        return head;
    }
};

int main(){

}
#include<bits/stdc++.h>
using namespace std;
#include"List.h"
class Solution {

    public :
    ListNode *insertion_sort(ListNode * head){
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        head = head->next;
        dummy->next->next = nullptr;
        ListNode *next;
        while(head){
            ListNode * temp = dummy;
            while (temp)
            {
               // check for last node because below(else if) condition will give error
            if(temp->next == NULL){
                next = head->next;
                head->next = temp->next;
                temp->next = head;
                head = next;
                break;
            }else if(temp->next->val > head->val){
                next = head->next;
                head->next = temp->next;
                temp->next = head;
                head = next;
                break;
            }
             temp = temp->next;
            
            } 
        }
        return dummy->next;
    }
};
int main(){
    List list;
    int n; cin>>n;
    for(int i = 0; i< n;i++){
        int x ;cin>>x;
        list.insert(x);
    }
    Solution obj;
    ListNode * head = list.headptr();
    head = obj.insertion_sort(head);
    display(head);
    return 0;
}
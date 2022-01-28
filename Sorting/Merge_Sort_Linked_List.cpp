#include<bits/stdc++.h>
using namespace std;
#include "List.h"
class Solution {
    public:
     ListNode* sortList(ListNode* &head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }       
        ListNode * mid = getMid(head);
        ListNode * left = sortList(head);
        ListNode * right = sortList(mid);
        ListNode * newList = mergeTwoLists(left,right);
        return newList;
    }
    private :
    ListNode *mergeTwoLists(ListNode *&list1, ListNode *&list2)
    {

        ListNode *temp = new ListNode(-1);
        ListNode *ans = temp;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        (list1 != NULL) ? temp->next = list1 : temp->next = list2;
        return ans->next;
    }
    ListNode* getMid(ListNode* head) {
        ListNode * midPrev = nullptr;
        while (head != nullptr && head->next != nullptr)
        {
           midPrev = (midPrev == nullptr) ? head : midPrev->next;
           head = head->next->next;
        }
        ListNode * mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
        
    }
};
int main(){
     int n;cin>>n;
     List list;
     for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list.insert(x);
    }
    Solution obj;
    ListNode * head = list.headptr();
    head = obj.sortList(head);
    display(head);
    return 0;
}
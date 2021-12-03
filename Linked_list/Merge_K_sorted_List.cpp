#include <bits/stdc++.h>
using namespace std;
#include "List.h"
class Solution
{
private:
   ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
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
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)return nullptr;
        if(n == 1 )return lists[0];
        ListNode * head = mergeTwoLists(lists[0],lists[1]);
        if(n == 2 )return head;
        mergeKLists(lists,head);
        return head;
    }
    private:
    void mergeKLists(vector<ListNode*>& lists,ListNode*&head,int idx = 2) {      
        if(lists[idx]!=NULL)
        head = mergeTwoLists(head,lists[idx]);
        if(idx < lists.size()-1)
        mergeKLists(lists,head,idx+1);
    }
};
int main()
{
    int k;cin>>k;
    vector<ListNode*>lists;
    for(int i = 0; i < k; i++){
        int sz; cin>>sz;
        List list;
        for(int  j = 0; j < sz; j++ )
        {
            int x; cin>>x;
            list.insert(x);
        }

        lists.push_back(list.headptr());
    }
    Solution obj;
    ListNode * ans = obj.mergeKLists(lists);
    display(ans);
    return 0;
}
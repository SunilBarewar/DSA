#include <bits/stdc++.h>
#include "List.h"
using namespace std;



class Solution
{
private:
    ListNode *get(int index, ListNode *&head)
    {
        ListNode *temp = head;
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    int length(ListNode *&head)
    {
        ListNode *temp = head;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

public:
   ListNode* removeNthFromEnd(ListNode* &head, int n) {
        if(head->next == NULL && n == 1)return nullptr;
        
        int len = length(head);
        if(n == len){
            ListNode * temp = head;
            head =  head->next;
            delete(temp);
            return head;
        }
        ListNode * prev = get(len - n,head);
        ListNode * temp = prev->next;
        prev->next = temp ->next;
        delete(temp);
        return head;
    }
};
int main()
{
    List list;
    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x; cin>>x;
        list.insert(x);
    }
    int k ;cin>>k;
    Solution obj;
    ListNode *head = list.headptr();
    ListNode *Head = obj.removeNthFromEnd(head,k);
    list.display(Head);

    return 0;
}
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
    ListNode *swapN(ListNode * &head,int k){
        int len = length(head);
        ListNode *num1 = get(k,head);
        ListNode * num2 = get(len-k+1,head);

        swap(num1->value,num2->value);
        return head;
    }
};
int main()
{
    LL list;
    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x; cin>>x;
        list.insert(x);
    }
    int k ;cin>>k;
    Solution obj;
    ListNode *head = list.start();
    ListNode *Head = obj.swapN(head,k);
    list.display(Head);

    return 0;
}
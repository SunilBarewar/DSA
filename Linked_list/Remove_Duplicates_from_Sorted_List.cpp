#include <bits/stdc++.h>
#include "List.h"
using namespace std;

class Solution
{
    public:
    ListNode *deleteDuplicates(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = head;
        ListNode *node = head;

        while (node->next != NULL)
        {

            if (node->val == node->next->val)
            {
                ListNode *temp = node->next;
                node->next = node->next->next;
                delete (temp);
            }
            else
            {
                node = node->next;
            }
        }
        return newHead;
    }
};
int main()
{
    List list;
    list.insert(1);
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    list.insert(4);
    list.insert(4);

    ListNode * head = list.headptr();
    Solution obj;
     head = obj.deleteDuplicates(head);
     list.display(head);
    return 0;
}
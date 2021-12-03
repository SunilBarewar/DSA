#include <bits/stdc++.h>
using namespace std;
#include"List.h"
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *evenHead = head->next;

        ListNode *odd = head;
        ListNode *even = head->next;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        odd->next = evenHead;
        if (even)
            even->next = NULL;
        return head;
    }
};
int main()
{

    return 0;
}
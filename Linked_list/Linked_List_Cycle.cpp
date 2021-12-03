#include <bits/stdc++.h>
#include "List.h"
using namespace std;

class Solution
{    
public:
    bool hasCycle(ListNode *&head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        if (head == NULL || head->next == NULL)
            return false;
        do
        {
            fast = fast->next;
            slow = slow->next;
            if (fast)
            {
                fast = fast->next;
            }
        } while (fast != slow && fast);

        return fast;
    }

    
};

int main()
{
    List list;
    list.insert(2);
    list.insert(9);
    list.insert(4);
    list.insert(3);
    list.insert(8);
    list.insert(9);
    list.insert(99);
    list.insert(19);
    // creating cycle in list

    list.makeCycle();
    ListNode * head = list.headptr();
    Solution obj;
    cout<< obj.hasCycle(head);
    return 0;

}
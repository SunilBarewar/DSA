#include <bits/stdc++.h>
using namespace std;
#include "List.h"
class Solution
{

public:
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
};
int main()
{
    List l1, l2;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l1.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        l2.insert(x);
    }
    Solution obj;
    ListNode *merged = obj.mergeTwoLists(l1.headptr(), l2.headptr());
    display(merged);
    return 0;
}
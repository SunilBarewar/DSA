#include <bits/stdc++.h>
#include "List.h"
using namespace std;

ListNode *swapNodes(ListNode *&head)
{

    if (head == NULL || head->next == NULL)
        return head;
    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *dummyHead;
    ListNode *prev = NULL;
    ListNode *next;
    dummyHead = head->next;
    while (first != NULL && second != NULL)
    {
        next = second->next;
        second->next = first;
        first->next = next;

        if (prev != NULL)
            prev->next = second;
        prev = first;
        // upating first and second
        first = next;
        if (first != NULL)
            second = first->next;
    }
    return dummyHead;
}
ListNode *swapNodes2(ListNode *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
        ListNode*newHead = head->next;
    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *next;
    next = second->next;
    second->next = first;
    first->next = next;
    first = next;
    if (first != NULL)
        second = first->next;
    head->next = swapNodes2(first);
    return newHead;
}
int main()
{
    LL list;
    list.insert(2);
    list.insert(7);
    list.insert(3);
    list.insert(9);
    list.insert(11);
    // list.insert(10);
    list.display();
    // Node * head = list.start();
    ListNode *head = list.start();
    // list.display(head);
    ListNode *temp = swapNodes2(head);
    list.display(temp);
    return 0;
}
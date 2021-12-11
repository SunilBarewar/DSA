#include<iostream>
using namespace std;
#include"List.h"

class Solution {
    private:
     ListNode *getNode(ListNode *&head,int index)
    {
        ListNode *temp = head;
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* &head, int k) {
        int len = 1;
        ListNode * last = head;
        while(last->next != nullptr){
            len++;
            last = last->next;
        }

        k = k%len;
        if(k > 0){
            ListNode * prev = getNode(head,len-k);
            ListNode * newHead = prev->next;
            prev->next = nullptr;
            last->next = head;
            head = newHead;
        }
        return head;
    }
};

int main(){

}
#include <bits/stdc++.h>
#include "List.h"
using namespace std;



class Solution
{
public:
   void Delete(ListNode* &head, int M ,int N) {
        if(head == NULL)return;
        ListNode * temp = head;
        //1 ->2 ->3 ->4 ->5 ->6 -> 7 -> 8 , M =2 , N = 2
        while(temp){
            int count1 = 1;
            // skip M nodes
            while(temp && count1 < M){
                temp = temp->next;
                count1++;
            }
            if(temp == NULL)break;
            ListNode *prev = temp;
            temp = temp->next;
            int count2  = 0;
            // delete N nodes           
            while(temp && count2 < N){
                temp = temp->next;
                count2++;
            }   
            prev->next = temp;
        }
    }
};
int main()
{
    List list;
    int s; cin>>s;
    for(int i = 0; i < s; i++)
    {
        int x; cin>>x;
        list.insert(x);
    }
    int m,n;cin>>m>>n;
    Solution obj;
    ListNode *head = list.headptr();
    obj.Delete(head,m,n);
    list.display(head);
    return 0;
}

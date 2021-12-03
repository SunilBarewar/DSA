#include<bits/stdc++.h>
using namespace std;
#include"List.h"

class Solution {

    public:
    bool isPalindrome(ListNode*&head) {
        string s;
        ListNode* temp = head;
        
        while(temp != NULL){
        char ch = temp->val+'0';
            s+=ch;
            temp = temp->next;
        }
        int start  = 0;
        int end = s.length()-1;

        while(start < end){
            if(s[start]!= s[end])return false;
            start++;end--;
        }
        return true;
    }
};
int main()
{

return 0;
}
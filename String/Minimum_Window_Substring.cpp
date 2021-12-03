#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> mp2;
        int sz2 = t.length();
        int sz1 = s.length();
        for (int i = 0; i < sz2; i++)
        {
            mp2[t[i]]++;
        }
        int i = -1;
        int j = -1;
        int cnt = 0;
         int ans = INT_MAX;
         int idx = -1;
        unordered_map<char, int> mp1;
        while (true)
        {
            bool flag1 = false;
            bool flag2 = false;

            while (i < sz1 && cnt < sz2)
            {
                i++;
                char ch = s[i];
                mp1[ch]++;
                if (mp1[ch] <= mp2[ch])
                    cnt++;
                flag1 = true;
            }
            while (j <= i && cnt == sz2)
            {
                j++;
                char ch = s[j];
                if (mp1[ch] == 1)
                    mp1.erase(ch);
                else
                    mp1[ch]--;
                if (mp1[ch] < mp2[ch])
                {
                    cnt--;
                    int tempLen = i - j+1;
                    if(tempLen < ans)
                    {
                        ans = tempLen;
                        idx = j;
                    }
                }

                flag2 = true;
            }
            
            if (flag1 == false && flag2 == false)
                break;
        }
        if(idx == -1)return "";
        return s.substr(idx,ans);
    }
};
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    Solution obj;
    cout<<obj.minWindow(s,t);
    return 0;
}
/*
// using only one map
int r=s.size(),ans=INT_MAX,idx=-1;
         unordered_map<char, int> m;
         for(auto i: t)
             m[i]++;
         int cnt=m.size(),j=0;
         for(int i=0; i<r; i++){
             if(--m[s[i]]==0)cnt--;
             while(cnt==0){
                 int templength=i-j+1;
                 if(templength<ans){
                     ans=templength;
                     idx=j;
                 }
                 if(++m[s[j]]==1)
                     cnt++;
                 j++;
             }
         }
         if(idx==-1)return "";
         return s.substr(idx,ans);
*/
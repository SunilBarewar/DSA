#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string s){
        int start  = 0;
        int end = s.length()-1;

        while(start <=end){
            if(s[start]!= s[end])return false;
            start++;end--;
        }
        return true;
    }
public: 
    string longestPalindrome(string s)
    {
        string ans = "";
        int maxPal = 1;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j<n ; j++)
            {
                if(s[i]==s[j])
                {
                    int l=j-i+1;
                    if((maxPal<=l) && isPalindrome(s.substr(i,l)))
                    {                    
                        ans=s.substr(i,l);
                        maxPal=l;
                    }
                }
            }
        }
       
        return ans;
    }

};
int main()
{
    string s;cin>>s;
    Solution obj;
    cout<<obj.longestPalindrome(s);
    return 0;
}
// find all substrings
    // vector<string>sub;
//  for (int i = 0; i < s.length(); i++)
    //     {
    //         for (int j = 1; j<=s.length()-i ; j++)
    //         {
    //             string temp = s.substr(i,j);
    //             sub.push_back(temp);
    //         }
    //     }
    //     for(string x : sub)cout<<x<<endl;
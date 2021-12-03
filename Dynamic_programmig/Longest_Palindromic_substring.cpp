#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string longestPalindrome(string s)
    {
        int strlen = s.length();
        if(strlen == 0)return s;
        int start;
        int len = INT_MIN;
        bool dp[strlen][strlen] = {false};
        int cnt = 0;
        for (int gap = 0; gap < strlen; gap++)
        {
            for (int i = 0, j = gap; j < strlen; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = true;
                }
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                if (dp[i][j] == true)
                {
                    if (len < j - i + 1)
                    {
                        start = i;
                        len = j - i + 1;
                    }
                    cnt++;
                };
            }
        }
        return s.substr(start, len);
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.longestPalindrome(s);
   
    return 0;
}
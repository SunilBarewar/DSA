#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int countHomogenous(string s)
    {
        int n = s.length();
        int ans = 0, len = 0;
        const int MOD = 1e9 + 7;
        long long sub;
        int j = 1;
        for (int i = 0; i < n; i++)
        {
            len++;
            if(s[i] !=s[j]){

                int even = len % 2 == 0 ? len : len +1;
                int odd = len % 2 == 0? len +1: len;
                sub = odd * even / 2;// this approach gives int overflow 
                ans = (ans % MOD + sub%MOD) % MOD;
                len = 0;
            }
            j++;
        }
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.countHomogenous(s);
    
    return 0;
}
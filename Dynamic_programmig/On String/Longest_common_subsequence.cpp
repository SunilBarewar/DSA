class Solution {
    int f(int i, int j, string &s, string &t,vector<vector<int>> &dp){
        if(i == 0 || j == 0)return 0;
        int &ans = dp[i][j];
        if(ans != -1)return ans;
        
        if(s[i-1] == t[j-1])return ans = 1 + f(i-1,j-1,s,t,dp);
        
        return ans = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
    }
// space optimization
  int longestCommonSubsequenc(string s, string t) {
       int n = s.size(), m = t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n,m,text1,text2,dp);
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m ; j++){
                int &ans = curr[j];
                if(s[i-1] == t[j-1]) ans = 1 + prev[j-1];
                else ans = max(prev[j], curr[j-1]);
            }
            prev =  curr;
        }
        return prev[m];
    }
public:
    
    int longestCommonSubsequence(string s, string t) {
       int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n,m,text1,text2,dp);
        
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m ; j++){
                int &ans = dp[i][j];
                if(s[i-1] == t[j-1]) ans = 1 + dp[i-1][j-1];
                else ans = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
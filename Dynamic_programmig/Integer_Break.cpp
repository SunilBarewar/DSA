#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
#define vvi vector<vector<int>>

class Solution {
    int f(int n,vector<int>&dp){
        if(n == 0)return 1;
        int ans = 1;
        for(int i = 1; i < n;i++){
            if(n - i >= 0)
            ans = max(ans ,i*max(n-i,f(n-i,dp)));
        }
        return dp[n] = ans;
    }
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};
int main(){
    int n;
    cin>>n;
    // vector<int>arr(n);
    // input cin>>arr[i];
    Solution obj;
    cout<<obj.integerBreak(n);
    return 0;
}
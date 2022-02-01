
#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
#define vvi vector<vector<int>>

class Solution {
     int f(vector<int>& coins, int amount,vector<int>&dp) {
        if(amount == 0)return 0;
        int ans = INT_MAX;
        if(dp[amount] != -1)return dp[amount];
        for(int coin : coins){
            if(amount - coin >= 0)
            ans = min(ans+0LL,f(coins,amount-coin,dp)+1LL);
        }
        return dp[amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = f(coins,amount,dp);
        return ans == INT_MAX ? -1 :ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input cin>>arr[i];
    int amount;cin>>amount;
    Solution obj;
    cout<<obj.coinChange(arr,amount);
    return 0;
}
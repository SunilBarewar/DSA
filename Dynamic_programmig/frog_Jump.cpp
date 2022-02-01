#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i < n;i++)

class Solution {

    public :
    int frogJump(vector<int>&nums,int idx,vector<int>&dp){
        if(idx == 0)return 0;
        if(dp[idx] != -1)return dp[idx];
        int cost = INT_MAX;
        cost = min( cost,frogJump(nums,idx-1,dp) + abs(nums[idx] - nums[idx -1]));
        if(idx > 1)
        cost = min(cost, frogJump(nums,idx-2,dp) + abs(nums[idx] - nums[idx -2]));
        return dp[idx] = cost;
    }
    int frogKjumps(vector<int>&nums,int idx,vector<int>&dp,int k){
         if(idx == 0)return 0;
        if(dp[idx] != -1)return dp[idx];

        int cost = INT_MAX;
        for(int j = 1; j <= k;j++){
            if(idx - j >= 0) 
        cost = min(cost,frogJump(nums,idx-j,dp) + abs(nums[idx] - nums[idx -j]));
        }
        
        return dp[idx] = cost;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input{
        cin>>arr[i];
    }
    int k; cin>>k;
    Solution obj;
    vector<int>dp(n+1,-1);
    cout<<obj.frogKjumps(arr,n-1,dp,k);
    // int prev = 0;
    // int prev2 = 0;
    // for(int i = 1; i< n;i++){
    //     int l = prev + abs(arr[i] - arr[i-1]);
    //     int r = INT_MAX;
    //     if(i > 1)
    //     r = prev2+ abs(arr[i] - arr[i-2]);
    //    int curr = min(l,r);
    //    prev2 = prev;
    //    prev = curr;
    // }
    // cout<<prev<<endl;
    
    return 0;
}

/*
dp[0] = 0;
    for(int i = 1; i< n;i++){
        int l = dp[i - 1] + abs(arr[i] - arr[i-1]);
        int r = INT_MAX;
        if(i > 1)
        r = dp[i - 2] + abs(arr[i] - arr[i-2]);
        dp[i] = min(l,r);
    }
    cout<<dp[n-1]<<endl;
*/
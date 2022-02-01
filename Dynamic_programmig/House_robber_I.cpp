#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
    private:
    int fun(vector<int>&arr, int idx,int dp[]){
         if(idx == 0)return arr[idx];
        if(idx < 0)return 0;

        if(dp[idx] != -1)return dp[idx];

        int pick = arr[idx]+ fun(arr,idx - 2, dp);
        int notPick = 0 + fun(arr,idx-1,dp); 

        return dp[idx] = max(pick,notPick);
    }
    public :
    int maxSum(vector<int>&nums){
        int n = nums.size();
        int dp[n] ;
        memset(dp,-1,sizeof(dp));
        dp[0] = nums[0];
        // tabulation
        int ans = 0;
        for(int i= 1; i< n;i++){
            int pick = nums[i] + ((i > 1) ? dp[i-2] : 0);
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick); 
        }
        // return fun(nums,n-1,dp);
        return dp[n-1];
    }

};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input{
        cin>>arr[i];
    }
    Solution obj;
    // cout<<obj.maxSum(arr);
    int prev1 = arr[0];
    int prev2 = 0;
    for(int i = 1; i<n;i++){
        int pick = arr[i] + prev2;
        int notPick = prev1;

        int curr = max(pick,notPick);
        prev2 = prev1;
        prev1 = curr; 
    }
    cout<<prev1;
    return 0;
}
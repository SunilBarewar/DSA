#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
    private:
    int fun(vector<int>&arr, int idx,vector<int>&dp){
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
        vector<int>dp(n,-1);
        return fun(nums,n-1,dp);
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
    cout<<obj.maxSum(arr);
    return 0;
}
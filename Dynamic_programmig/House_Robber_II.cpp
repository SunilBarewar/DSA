#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
    private:
    int fun(vector<int>&arr, int idx,int dp[],bool flag){
        if(idx == 0 && flag)return 0;
        else if(idx == 0)return arr[idx];
        if(idx < 0)return 0;
        
        if(dp[idx] != -1)return dp[idx];
        
        int pick = arr[idx]+ fun(arr,idx - 2, dp,flag);
        int notPick = 0 + fun(arr,idx-1,dp,flag); 
        return dp[idx] = max(pick,notPick);
    }
    public :
    int maxSum(vector<int>&nums){
        int n = nums.size();
        int dp[n] ;
        memset(dp,-1,sizeof(dp));
        int first = fun(nums,n-1,dp,true);
        memset(dp,-1,sizeof(dp));
        int second = fun(nums,n-2,dp,false);
        return max(first,second);
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
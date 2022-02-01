#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
    int lis(int idx,vector<int>&a,vector<int>&dp){
        if(dp[idx] != -1)return dp[idx];
        int ans = 1;
        for(int i = 0; i < idx; i++){
            if(a[idx] > a[i]){
                ans = max(ans,lis(i,a,dp)+1);
            }
        }
        return dp[idx] = ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int>dp(n+1,-1);
        for(int i = 0; i<= n; i++){
            ans = max(ans,lis(i,nums,dp));
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input cin>>arr[i];
    Solution obj;
    cout<<obj.lengthOfLIS(arr);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vector<int>>
//https://leetcode.com/problems/frog-jump/
class Solution {
    int binary_search(vector<int>&nums,int lo,int hi,int target){
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                hi = mid -1;
            }else{
                lo = mid+1;
            }
        }
        return -1;
    }
    int n;
    bool f(vector<int>&nums,int idx,int k,vector<vector<int>>&dp){
        if(idx == n-1)return true;
        if(dp[idx][k] != -1)return dp[idx][k];
        // last == 1, k-1
        
        for(int jump=k-1; jump<=k+1; jump++){
            int ind = binary_search(nums,idx+1,n-1,nums[idx]+jump);
            if(jump > 0 && ind != -1){
                if(f(nums,ind, jump,dp)) return dp[idx][k] = 1;
            }
        }
        return dp[idx][k] = 0;

    }
public:
    bool canCross(vector<int>& stones) {
        this->n = stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // vector<int>dp(n+1,-1);
        return f(stones,0,0,dp);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i< n;i++)
        cin>>arr[i];
    Solution obj;
    obj.canCross(arr) ? cout<<"true"<<endl : cout<<"false"<<endl;
    return 0;
}
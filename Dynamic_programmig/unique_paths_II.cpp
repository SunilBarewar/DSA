#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
// Recursion and memoization
int f(int i ,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
    if(i < 0 || j < 0 || arr[i][j] == 1)return 0;
    if(i == 0 &&  j == 0)return 1;
    
    if(dp[i][j] != -1)return dp[i][j];
    int up = f(i-1,j,arr,dp);
    int left = f(i,j-1,arr,dp);
    return dp[i][j] = up+left;
}
int SpaceOptimized(int m, int n,vector<vector<int>>&arr){
    vector<int>prev(n,0);
     for(int i  = 0; i < m; i++){
         vector<int>curr(n,0);
        for(int j = 0; j < n;j++){
            if(arr[i][j] == 1)curr[j] = 0;
            else if(i == 0 && j == 0)curr[0] = 1;
            else{
                int up = 0, left = 0;
                if(i > 0)up = prev[j];
                if(j > 0)left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}
int uniquePathsII(int m, int n,vector<vector<int>>&arr) {
	vector<vector<int>>dp(m,vector<int>(n,0));
// tabulation
    for(int i  = 0; i < m; i++){
        for(int j = 0; j < n;j++){
            if(arr[i][j] == 1)dp[i][j] = 0;
            else if(i == 0 && j == 0)dp[0][0] = 1;
            else{
                int up = 0, left = 0;
                if(i > 0)up = dp[i-1][j];
                if(j > 0)left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr(m,vector<int>(n));
    input {
        for(int j  = 0; j < n;j++)cin>>arr[i][j];
    }
    cout<<uniquePathsII(m,n,arr)<<endl;
    cout<<SpaceOptimized(m,n,arr);
    return 0;
}
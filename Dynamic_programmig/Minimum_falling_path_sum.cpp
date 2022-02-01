#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
    int n  = 0;
    int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(i < 0 || j < 0 || j >= n)return INT_MAX-100;
        if(i == 0)return matrix[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int  a =  matrix[i][j] + f(i-1,j-1,matrix,dp);
        int  b =   matrix[i][j] + f(i-1,j,matrix,dp);
        int  c =   matrix[i][j] + f(i-1,j+1,matrix,dp);
        return dp[i][j] = min({a,b,c});
    }
    /*for(int i = 0; i < n;i++)
           ans = min(ans,f(n-1,i,matrix,dp));
    
        return ans;*/
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // int ans = INT_MAX;
        // for(int i = 0; i < n;i++)
        //    ans = min(ans,f(n-1,i,matrix,dp));
    
        // return ans;
        for(int i = 0; i< n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i< n;i++){
            for(int j = 0; j < n;j++){
                int a =  j > 0 ? matrix[i][j] + dp[i-1][j-1] : INT_MAX;
                int b = matrix[i][j] + dp[i-1][j];
                int c = j < n-1 ? matrix[i][j] + dp[i-1][j+1] : INT_MAX;
                dp[i][j] = min({a,b,c});
            }
        }
        int ans =  INT_MAX;
        for(int i = 0; i< n;i++){
            ans = min(ans,dp[n-1][i]);
        }

        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    input {
        for(int j = 0; j < n;j++)
        cin>>arr[i][j];
    }    Solution obj;
    cout<<obj.minFallingPathSum(arr);
    return 0;
}
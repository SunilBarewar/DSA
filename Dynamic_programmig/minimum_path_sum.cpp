#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
private:
    
    int f(vector<vector<int>>& grid,int i, int j,vector<vector<int>>& dp){
        if(i == 0 && j == 0)return grid[i][j];
        if(i < 0 || j < 0)return 1e9;
        if(dp[i][j] != -1)return dp[i][j];
        int right = grid[i][j] + f(grid,i,j-1,dp);
        int down = grid[i][j] + f(grid,i-1,j,dp);
        // return grid[i][j] + min(f(grid, i, j -1), f(grid,i-1,j));
        return dp[i][j] = min(right , down);
    }
    int minPathsumSpaceOp(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<int>prev(m,0);
        // return f(grid,n-1,m-1,dp);
        for(int i = 0; i< n;i++){
            vector<int>curr(m,0);
            for(int j = 0; j < m;j++){
                if(i == 0 && j == 0)curr[j] = grid[i][j];
                else {
                    int up = 1e9, left = 1e9;
                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + curr[j-1];
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int>prev(m,0);
        // return f(grid,n-1,m-1,dp);
        for(int i = 0; i< n;i++){
            for(int j = 0; j < m;j++){
                if(i == 0 && j == 0)dp[i][j] = grid[i][j];
                else {
                    int up = 1e9, left = 1e9;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i = 0; i< n;i++){
        for(int j = 0; j <m;j++)
             cin>>arr[i][j];
    }
    Solution obj;
    cout<<obj.minPathSum(arr);
    return 0;
}
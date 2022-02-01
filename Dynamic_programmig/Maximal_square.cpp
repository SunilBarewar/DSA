#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
#define vvi vector<vector<int>>
class Solution {
    int f(vector<vector<char>>&matrix,int i, int j,vector<vector<int>>&dp){
        if(i < 0 || j < 0)return 0;
        if(matrix[i][j] == '0')return 0;
        if(dp[i][j] != -1)return dp[i][j];

        int up = f(matrix,i-1,j,dp);
        int left = f(matrix,i,j-1,dp);
        int diagonal = f(matrix,i-1,j-1,dp);
        int area = 1 + min({up,left,diagonal});    
        return dp[i][j] = area;
    }
    /*
     for(int i = n-1; i >= 0;i--){
        for(int j = m-1;j >= 0 ;j--){
            if(matrix[i][j] == '1'){
                area = max(area,f(matrix,i,j,dp));
            }
        }
    }
    */
    public :
    int maximalSquare(vector<vector<char>>&matrix){
    int n = matrix.size(),m = matrix[0].size();
    int area = 0;
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i  = 0; i< n;i++){
        
    }
    return area*area;
}
};
int main(){
  int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i = 0; i< n;i++){
        for(int j = 0; j <m;j++)
             cin>>arr[i][j];
    }
    Solution obj;
    cout<<obj.maximalSquare(arr);
    return 0;
}
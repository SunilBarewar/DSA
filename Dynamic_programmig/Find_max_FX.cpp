#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
#define vvi vector<vector<int>>
//https://www.codingninjas.com/codestudio/problems/maximum-value-of-f-x-ii_2245751?source=youtube&campaign=Strivercontest6thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Strivercontest6thfeb&leftPanelTab=1
int f(int i , int j, string&s, string &t,int n,int m,vector<vector<int>>& dp){
    if(i < 0 || j < 0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int compare = 0;
    
    if(s[i] == t[j]) compare = 1 + f(i-1,j-1,s,t,n,m,dp);
    
    int notCompare = max(f(i-1,j,s,t,n,m,dp), f(i,j-1,s,t,n,m,dp));
    
    return dp[i][j] = max(compare,notCompare);
}

int maxFXII(string &s, string &t, int n, int m){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    // Write your code here.
    return 2 * f(n-1,m-1,s,t,n,m,dp);
    
}
int main(){
    int n,m;
    cin>>n>>m;
   string s,t;
   cin>>s>>t;
   cout<<maxFXII(s,t,n,m);
    return 0;
}
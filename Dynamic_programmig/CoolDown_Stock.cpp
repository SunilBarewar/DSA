#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
#define vvi vector<vector<int>>

class Solution {
    int f(vector<int>&a,int i , int prevBuyed,bool flag,vector<int>&dp){
        if(i >= a.size())return 0;
        // if(dp[i] != -1)return dp[i];
        int ans = INT_MIN;
        if(!flag){
            cout<<i<<endl;
            int buy = f(a,i+1,a[i],true,dp);
            int notBuy = f(a,i+1,0,false,dp);
            ans = max({buy,notBuy,ans});
        }else{
            cout<<i<<"  "<< prevBuyed<<endl;
            int sell = a[i] - prevBuyed + f(a,i+2,0,false,dp);
            int notsell =  f(a,i+1,prevBuyed,true,dp);
            ans = max({ans,sell ,notsell});
        }
        return  ans;
    }
    public :
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        vector<int>dp(n,-1);
        int ans = f(prices,0,0,false,dp);
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input cin>>arr[i];
    Solution obj;
    cout<<obj.maxProfit(arr);
    return 0;
}
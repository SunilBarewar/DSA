#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
//https://leetcode.com/problems/best-sightseeing-pair/
    int f(vector<int>&values,int i,int prev){
        if(i == values.size())return 0;
        int ans = INT_MIN;
         ans = max(ans , prev + values[i]-i);
         prev = max(prev,values[i]+i);
         return max (ans,f(values,i+1,prev)); 
    }
    public :
    int maxScoreSightseeingPair(vector<int>& values) {
       int n = values.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(values,1,values[0]); 
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input cin>>arr[i];
    Solution obj;
    cout<<obj.maxScoreSightseeingPair(arr);
    return 0;
}
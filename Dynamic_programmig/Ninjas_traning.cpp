//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)

class Solution {
    int dpSpaceOptimized(int n, vector<vector<int>> &points){
        vector<int>prev(n,0);
        prev[0] = max(points[0][1],points[0][2]);
        prev[1] = max(points[0][0],points[0][2]);
        prev[2] = max(points[0][0],points[0][1]);
        prev[3] = max({points[0][0],points[0][1],points[0][2]});

        for(int day = 1; day < n;day++){
            vector<int>temp(4,0);
            for(int last = 0; last < 4; last++){

                for(int task = 0; task < 3; task++){
                    if(task != last)
                   temp[last] = max(points[day][task] + prev[task],prev[last]); 
                }
            }
            prev = temp;
        }
        return prev[3];
    }
    int f(int day , int last,vector<vector<int>> &points,vector<vector<int>>&dp){
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i < 3;i++){
                if(i != last){
                    maxi = max(maxi,points[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last] != -1)return dp[day][last];
        int maxi = 0;
        for(int task = 0; task < 3;task++){
          if(task != last){
              int point = points[day][task] + f(day-1,task,points,dp);
                maxi = max(maxi,point);
             }      
        }
        return dp[day][last] = maxi;
        
    }
    public :
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>>dp(n,vector<int>(4,0));
        // return f(n-1,3,points,dp);
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][0],points[0][1]);
        dp[0][3] = max({points[0][0],points[0][1],points[0][2]});

        for(int day = 1; day < n;day++){
            for(int last = 0; last < 4; last++){
                dp[day][last]  = 0;
                for(int task = 0; task <=2; task++){
                    if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(point,dp[day][last]);
                    } 
                }
            }
        }
        return dp[n-1][3];
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3,0));
    input {
        for(int j = 0; j < 3;j++){
            cin>>arr[i][j];
        }
    }
    Solution obj;
    cout<<obj.ninjaTraining(n,arr);
    return 0;
}
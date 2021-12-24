#include<bits/stdc++.h>
using namespace std;
#define  matrix vector<vector<int>>
void print(matrix & ans);
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans; 
        int idx = 0;
        int n = intervals.size();
        while(idx < n){
            if(intervals[idx][0] < newInterval[0]){
                ans.push_back(intervals[idx]);
                idx++;
            } else{
                break;
            }
        }
        if(ans.size() == 0 || newInterval[0] > ans.back()[1]){
            ans.push_back(newInterval);
        }else{
            vector<int>& lastInterval = ans.back();
            lastInterval[1] = max(lastInterval[1],newInterval[1]);
        }
        while(idx < n){
             vector<int>& lastInterval = ans.back();
             if(lastInterval[1] >= intervals[idx][0]){
                 //merging
                 lastInterval[1] = max(lastInterval[1],intervals[idx][1]);
             }else {
                 ans.push_back(intervals[idx]);
             }
             idx++;
        }
        return ans;
    }
};
void print(matrix & ans){
     for(auto &v: ans){
            for(int x : v){
                cout<<x<<" ";
            }cout<<endl;
    }
}
int main(){
    int n;cin>>n;
    matrix intervals(n,vector<int>(2));
    for(int i = 0; i<n;i++){
        for(int j = 0; j < 2;j++){
            cin>>intervals[i][j];
        }
    }
    Solution obj;
    vector<int>newInterval (2);
    cin>>newInterval[0]>>newInterval[1];
    matrix ans = obj.insert(intervals,newInterval);
    print(ans);
    return 0;
}

/*
     for(auto &interval : intervals){
            if(ans.size() == 0)ans.push_back(interval);
            else{
                 if(interval[0] < newInterval[0])ans.push_back(interval);
                vector<int>& prevInterval = ans.back();
                if(prevInterval[1] >= newInterval[0] && newInterval[1] >= interval[0]){
                    prevInterval[0]  = min({prevInterval[0],newInterval[0]});
                    prevInterval[1] = max({prevInterval[1],newInterval[1],interval[1]});
                }
            }
        }
*/
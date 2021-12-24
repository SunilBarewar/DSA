#include<bits/stdc++.h>
using namespace std;
#define  matrix vector<vector<int>>
class Solution {
    private:
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0] < b[0])return true;
        return false;
    }
    public :
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        // for(auto &v: intervals){
        //     for(int x : v){
        //         cout<<x<<" ";
        //     }cout<<endl;
        // }

        vector<vector<int>> ans;
        // ans.push_back(intervals[0]);
        int n= intervals.size();

        for(vector<int>&interval: intervals){
            if(ans.size() == 0){
                ans.push_back(interval);
            }else{
                vector<int>& prevInterval = ans.back();
             if(interval[0] <= prevInterval[1]){
                    prevInterval[1] = max(interval[1],prevInterval[1]);;
                }else{
                    ans.push_back(interval);
                }
            }
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
    matrix ans = obj.merge(intervals);
    print(ans);
    return 0;
}
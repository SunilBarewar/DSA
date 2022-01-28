#include<bits/stdc++.h>
using namespace std;

class Solution {

    public :
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        stack<vector<int>>st;
        int diff = INT_MAX;
        for(int i = 0,j = 1; j < n;i++,j++){
            if(arr[j] - arr[i] < diff){
                while(!st.empty()){
                    st.pop();
                }
                st.push({arr[i],arr[j]});
                diff = arr[j] - arr[i];
            }else if(arr[j] - arr[i] == diff)
            st.push({arr[i],arr[j]});
        }
        
        vector<vector<int>> ans(st.size());
        int i = st.size() -1;
         while(!st.empty()){
             ans[i] = st.top();
             st.pop();
             i--;
       }
        return ans;
    }

    vector<vector<int>> minimumAbsDifference2(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        stack<vector<int>>st;
        int diff = INT_MAX;
        for(int i = 0,j = 1; j < n;i++,j++){
            if(arr[j] - arr[i] < diff){
                ans.clear();
                ans.push_back({arr[i],arr[j]});
                diff = arr[j] - arr[i];
                  cout<<diff<<endl;
            }else if(arr[j] - arr[i] == diff)
            ans.push_back({arr[i],arr[j]});
        }
        return ans;
    }
};
void cout_Arrays(vector<int>&v){
    for(int x : v){
        cout<<x<<" ";
    }cout<<endl;
}
int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i = 0; i< n;i++)cin>>arr[i];
    Solution obj;
    vector<vector<int>> ans;
    ans = obj.minimumAbsDifference(arr);
    for(vector<int>&v : ans){
        cout_Arrays(v);
    }
    return 0;
}
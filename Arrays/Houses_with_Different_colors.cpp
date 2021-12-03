#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// O(N^2) solution
    int maxDistance(vector<int>& arr) {
        
        int n = arr.size();
        int mxDistance =0;
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n;j++){
                if(arr[i] != arr[j]){
                    mxDistance = max(mxDistance,j-i);
                }
            }
        }
        return mxDistance;
    }
     int maxDistanceOn(vector<int>& arr) {
        
        int n = arr.size();
        int j = n -1;
        while (arr[0] == arr[j])j--;
        int i = 0; 
        while(arr[i] == arr[n-1]) i++;
        int mxDistance = max(j,n-1-i);
        return mxDistance;
    }
};

int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i = 0; i< n;i++){
        cin>>v[i];
    }
    Solution obj;
    cout<<obj.maxDistance(v);
return 0;
}
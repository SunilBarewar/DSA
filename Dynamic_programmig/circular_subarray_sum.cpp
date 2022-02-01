#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
class Solution {
    int sum = 0;
    bool positive  = false;
    int inveredSum = 0;
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int currSum = 0;
        int maxSum = INT_MIN;
       
        for(int i = 0 ; i < n;i++){
            if(arr[i] >= 0)positive = true;
            currSum +=(-arr[i]);
            sum+=(-arr[i]);
            maxSum = max(maxSum,currSum);
            if(currSum < 0)currSum = 0;
        }
        return maxSum;
    }
    public :
    int maxSubarraySumCircular(vector<int>&arr) {

        int maxSum =  maxSubArray(arr);
        cout<<sum<<" "<<maxSum<<endl;
        if(positive == false || sum == 0)return *max_element(arr.begin(),arr.end());
        return -(sum-maxSum);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    input{
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.maxSubarraySumCircular(arr);
    return 0;
}
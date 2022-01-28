#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/missing-number/
class Solution {
// cycle sort algo
    public :
    int missingNumber(vector<int>&arr){
    int n = arr.size();
    int i =0;
   while(i < n)
    {
        int correct = arr[i];
        if(correct == i || correct > n - 1 )i++;
        else{
            int temp = arr[i];
            arr[i] = arr[correct];
            arr[correct] = temp;
        }
    }

    for(int index = 0; index< n;index++){
        if(arr[index] != index)
        return index;
    }
    return n;
}
};
int main(){
     int n ;cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i< n;i++)
        cin>>arr[i];
    Solution obj;
    obj.missingNumber(arr);
    return 0;
}
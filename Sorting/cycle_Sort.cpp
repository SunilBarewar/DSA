#include<bits/stdc++.h>
using namespace std;

void cycle_Sort(vector<int>&arr){
    int n = arr.size();
    int i =0;
   while(i < n)
    {
        int correct = arr[i] -1;
        if(correct == i )i++;
        else{
            int temp = arr[i];
            arr[i] = arr[correct];
            arr[correct] = temp;
        }
    }
}
int main(){
    int n ;cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i< n;i++)cin>>arr[i];
    cycle_Sort(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}
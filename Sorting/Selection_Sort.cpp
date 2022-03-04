#include<bits/stdc++.h>
using namespace std;

void selection_Sort(vector<int>&arr){
    int n = arr.size();

    for(int i = n -1; i > 0 ;i--){// 4 //3
        int maxN = 0;
        for(int j = 1; j <= i; j++){
            if(arr[j] > arr[maxN])maxN = j;
        }
        // swap
        int temp = arr[maxN];
        arr[maxN] = arr[i];
        arr[i] = temp;

        for(auto i : arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n ;cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i< n;i++)cin>>arr[i];
    selection_Sort(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}
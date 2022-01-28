#include<bits/stdc++.h>
using namespace std;

void insertion_Sort(vector<int>&arr){
    // 5 4 3 2 1
    int n = arr.size();
    bool swapped;
    for(int i = 0; i < n - 1; i++){
        int j = i+1;
        while(j>0 && arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;swapped= true;
        }
        for(auto i : arr){
        cout<<i<<" ";
    }cout<<endl;
    }
}
int main(){
     int n ;cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i< n;i++)cin>>arr[i];
    insertion_Sort(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}


/*

in insertion sort we are inserting the element 


*/
#include<bits/stdc++.h>
using namespace std;

void insertion_Sort(vector<int>&arr){
    // 5 4 3 2 1
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        int j = i+1;  
        bool swapped = false;
        printf("i = %d , j =  %d =>",i,j);
        while(j>0 && arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
                swapped = true;
        }
        // if(swapped)break;
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
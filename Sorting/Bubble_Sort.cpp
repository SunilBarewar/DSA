#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&arr){
    //5 4 3 2 1
    bool swapped;
    int n = arr.size();
    for(int i = 0; i < n ; i++){
        // for each step, max item will come at the last respective index
        swapped = false;
        for(int j = 1; j < n - i  ; j++){
            // swap if the item is smaller than the previous item
            if(arr[j] < arr[j -1]){
                //swap
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swapped = true;
            }
        }
        for(auto i : arr){
        cout<<i<<" ";
    }cout<<endl;
        if(!swapped)break; //!false == true
        
    }
}
int main(){
    int n ;cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i< n;i++)cin>>arr[i];
    bubble_sort(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}
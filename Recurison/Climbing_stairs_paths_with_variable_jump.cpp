#include <iostream>
using namespace std;

int countPaths(int arr[], int n,int index = 0){
    if(index == n)return 1;
    int cnt = 0;
    for(int jump= 1; jump <= arr[index]; jump++){
        if(jump+index<=n)
        cnt+=countPaths(arr,n,index+jump);
        else 
        break;
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<countPaths(arr,n)<<endl;
}
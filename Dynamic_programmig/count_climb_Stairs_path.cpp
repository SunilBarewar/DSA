#include <iostream>
using namespace std;
// memonization method
int countPaths(int n,int dp[]){
    if(n == 0)return 1;
    else if(n < 0)return 0;
    if(dp[n] != 0)return dp[n];
    int nm1 = countPaths(n -1,dp);
    int nm2 = countPaths(n -2,dp);
    int nm3 = countPaths(n -3,dp);
    int total = nm1 + nm2 + nm3;
    dp[n] = total;
    return total;

}

int main(){
    int n;
    cin>>n;
    int dp[n+1]= {0};
    cout<<countPaths(n,dp)<<endl;
}
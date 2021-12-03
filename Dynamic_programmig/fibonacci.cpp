#include<iostream>
using namespace std;

long long fib(long long n ,long long dp[]){
    if(n == 0 || n == 1){
        return n;
    }
    
    if(dp[n]!= 0)return dp[n];
    
    long long fib1 = fib(n-1,dp);
    long long fib2 = fib(n-2,dp);
    // sum of previous two numbers
    long long sum = fib1 + fib2;
    return sum;
}


int main(){
    long long n; 
    cin>>n;
    long long dp[n+1] = {0};// initializing with zero
    long long ans = fib(n,dp);
    cout<<ans<<endl;
}
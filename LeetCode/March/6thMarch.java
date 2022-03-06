class Solution {
    public int countOrders(int n) {
        long[] dp = new long[n+1];
        dp[1] = 1;
        int mod = (int)(1e9 + 7);
        
        for(int i = 2; i <= n;i++){
            dp[i] = (dp[i-1] * i * (2* i -1))%mod;
        }
        return (int)dp[n];
        
        // sapce optimized code no need of dp array
//         long prev = 1;
//         int mod = (int)(1e9 + 7);
//         for(int i = 2; i <= n;i++){
//             prev = (prev * i * (2* i -1))%mod;
//         }
//         return (int)prev;
    }
}
class Solution {
    int n;
    bool isPossible(vector<int>&nums,int maxSum, int m){
        int sum = 0,cnt = 1;
        for(int i = 0; i < n;i++){
            sum+= nums[i];
            if(sum > maxSum){
                sum = nums[i];
                cnt++;
            }
        }
        return cnt <= m;
    }
public://https://leetcode.com/problems/split-array-largest-sum/
    int splitArray(vector<int>& nums, int m) {
        
        this-> n = nums.size();
        int maxi = nums[0],sum = 0;
        for(int x : nums){
            maxi = max(x,maxi);
            sum+=x;
        }
        if(m == n)return maxi;
        if(m == 1)return sum;
        int lo = maxi;
        int hi = sum;
        int ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(isPossible(nums,mid,m) == true){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
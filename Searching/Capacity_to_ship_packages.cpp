class Solution {
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
    int n;
    bool isPossible(vector<int>&nums,int capacity, int days){
        int sum = 0,cnt = 1;
        for(int i = 0; i < n;i++){
            sum+= nums[i];
            if(sum > capacity){
                sum = nums[i];
                cnt++;
            }
        }
        return cnt <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        this->n = weights.size();
         int maxi = weights[0],sum = 0;
        for(int x : weights){
            maxi = max(x,maxi);
            sum+=x;
        }
        
        int lo = maxi;
        int hi = sum,ans = 0;
         while(lo <= hi){
            int mid = (lo+hi)/2;
            if(isPossible(weights,mid,days) == true){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
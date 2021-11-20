class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;
    // applying binary search on divisor not on element of array
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(nums,threshold,mid)){
                ans = mid ;
                hi = mid -1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
    
     bool isPossible(vector<int>&nums,int threshold ,int divisor){
        int count = 0;
        for(auto &num : nums){
            count+=(num/divisor);
            if(num % divisor) count++;
        }
        return count<=threshold;
    }
};
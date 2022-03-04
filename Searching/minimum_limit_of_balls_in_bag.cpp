class Solution {
//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
    int n;
    bool check(vector<int>&nums,int penalty,int maxOp){
        int cnt = 0;
        for(int i = 0; i < n;i++){
            cnt += (nums[i] / penalty);
            if(nums[i] % penalty == 0)
                cnt--;
        }
        return cnt <=  maxOp;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
       this->n = nums.size();
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int ans = hi;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(check(nums,mid,maxOperations) == true){
                ans = min(ans,mid);
                hi = mid -1;
            }else{
               lo = mid+1;
            }
        }
        return ans;
    }
};
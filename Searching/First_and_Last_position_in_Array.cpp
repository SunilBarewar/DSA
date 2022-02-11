class Solution {
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
    int binarySearch(vector<int>& nums, int target, bool range){
        int lo = 0, hi = nums.size() -1;
        int mid;
        int n = nums.size();
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            
            if(nums[mid] < target){
                lo = mid+1;
            }else if(nums[mid] > target){
                hi = mid - 1;
            }else{
                if(range)hi = mid - 1;
                else lo = mid + 1;
            }
            
        }
        if(range && (lo >= n  || nums[lo] != target ))lo = -1;
        else if(!range  && (hi < 0 || nums[hi] != target))hi = -1;
        return range ? lo : hi;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return {-1,-1};
       vector<int> ans(2);
        ans[0] = binarySearch(nums,target,true);
        ans[1] = binarySearch(nums,target,false);
        return ans;
    }
};
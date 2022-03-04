class Solution {
//https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
    int n;
    bool check(vector<int>&arr,int mid,int stores){
        int cnt = 0;
        for(int i = 0; i < n;i++){
            cnt += (arr[i]/mid) + (arr[i] % mid != 0);
        }
        
        return cnt <= stores;
    }
public:
    int minimizedMaximum(int stores, vector<int>& quantities) {
        this->n = quantities.size();
        int lo = 1, hi = INT_MAX;
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(quantities,mid,stores) == true){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
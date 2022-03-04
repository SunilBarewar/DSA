//https://leetcode.com/problems/magnetic-force-between-two-balls/
class Solution {
    int n;
    bool check(vector<int>&arr,int force,int balls){
        int cnt = 1;
        int prev = 0;
        for(int i = 1; i < n;i++){
            if(arr[i] - arr[prev] >= force){
                cnt++;
                prev = i;
            }
        }
        return cnt >=  balls;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        this->n = position.size();
        sort(position.begin(),position.end());
        int lo = 1, hi = INT_MAX;
        int mid,ans;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(check(position,mid,m) == true){
                ans = mid;
                lo = mid +1;
            }else{
                hi = mid -1;
            }
        }
        return ans;
    }
};
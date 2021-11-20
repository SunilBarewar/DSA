class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        if(h == piles.size())return hi;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(piles,h,mid)){
                ans = mid ;
                hi = mid -1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int>&piles,int h ,int speed){
        int count = 0;
        for(auto &p : piles){
            count+=(p/speed);
            if(p%speed) count++;
        }
        return count<=h;
    }
};
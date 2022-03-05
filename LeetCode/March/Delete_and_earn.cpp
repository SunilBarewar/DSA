class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10005, 0);
        
        for(int x : nums){
            count[x]+=x;
        }
        
        int pick = 0;
        int notPick = 0;
        for(int i = 1; i < 10005; i++){
            int curr = max(count[i]+pick, notPick);
            pick = notPick;
            notPick = curr;
        }
        return notPick;
    }
};
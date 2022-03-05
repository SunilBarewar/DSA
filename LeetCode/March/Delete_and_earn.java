class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] count = new int[10001];
            for (int num : nums) {
                count[num] += num;
            }
        int pick = 0; 
        int notPick =count[1];
        
        for(int i =2; i <= 10000;i++){
            int curr = Math.max(pick + count[i], notPick);
            pick = notPick;
            notPick = curr;
        }
        
        return notPick;
    }
}
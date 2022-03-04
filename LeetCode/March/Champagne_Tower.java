class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0)return 0;
        List<Double> prev = new ArrayList<>();
        prev.add(new Double(poured*1.0));
        
        while(query_row != 0){
            List<Double> curr = new ArrayList<>();
            curr.add(Math.max((prev.get(0) - 1)/2,0));

            for(int i = 1; i < prev.size(); i++){
                Double x = Math.max((prev.get(i-1)-1)/2 , 0) + Math.max((prev.get(i)-1)/2 , 0);
                curr.add(x);
            }
            
            curr.add(curr.get(0));
            prev = new ArrayList<>(curr);
	    query_row -= 1;
        }
        return Math.min(1, prev.get(query_glass));
    }
}
class Solution {
    int findRow(vector<vector<int>>& matrix, int target){
        int st = 0, end = matrix.size()-1;
        int m = matrix[0].size()-1, n = matrix.size();
        
        while(st <= end){
            int mid = (st + end)/2;
            // if(st < 0 || end >= n)return -1;
            if(matrix[mid][0] <= target && matrix[mid][m] >= target)return mid;
            else if(matrix[mid][0] < target)st = mid+1;
            else end = mid-1;
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix,target);
        if(row == -1)return 0;
        
        int st = 0, end =  matrix[0].size()-1;
        
        while(st <= end){
            int mid = (st + end)/2;
            
            if(matrix[row][mid] == target)return true;
            else if(matrix[row][mid] < target)st  = mid+1;
            else end = mid-1;
        }
        return false;
    }
};
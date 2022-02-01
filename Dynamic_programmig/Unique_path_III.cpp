#include<bits/stdc++.h>
using namespace std;
#define input  for(int i = 0; i< n;i++)
/*https://leetcode.com/problems/unique-paths-iii/
You are given an m x n integer array grid where grid[i][j] could be:

    1 representing the starting square. There is exactly one starting square.
    2 representing the ending square. There is exactly one ending square.
    0 representing empty squares we can walk over.
    -1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square
 to the ending square, that walk over every non-obstacle square exactly once.
*/
class Solution {
     private:
    int ans = 0, dir[5] {0, 1, 0, -1, 0};  // <- a common way to make 4-way exploration in dfs concise
	
	// checks if cell is valid. If none of 3 points mentioned in post is satisfied, it is a valid cell
    bool isValidCell(vector<vector<int>>& G, int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n && G[i][j] != -1 && G[i][j] != 3;
    }
	
    void dfs(vector<vector<int>>& G, int i, int j, int cellsToVisit) {
        if(not isValidCell(G, i, j)) return;   // return if cell is invalid
        if(G[i][j] == 2) {                     // reached end cell
            if(cellsToVisit == 0) ans++;       // if all cells are visited, increment valid path count
            return;                            // no further exploration possible after reaching end cell
        }
        G[i][j] = 3;                           // mark cell as visited
        for(int k = 0; k < 4; k++)             // explore path futher 4-directionally
            dfs(G, i + dir[k], j + dir[k+1], cellsToVisit - 1);    
        G[i][j] = 0;                           // backtrack
    } 
private:
     int x = 0 , y= 0,n = 0,m= 0;
    bool isValid(vector<vector<int>>& grid,int i, int j){
        return (i >= 0 && j >= 0 && j < n && i < m && grid[i][j] != -1 && grid[i][j] != 3); 
    }
     int f(int i, int j,vector<vector<int>>& grid,int zeros){
         if(!isValid(grid,i,j))return 0;
         if(grid[i][j] == 2){
             if(zeros == 0) return 1;
             else return 0;
             
        }
        int ans = 0;
        grid[i][j] = 3;
         ans += f(i-1,j,grid,zeros-1);
         ans += f(i+1,j,grid,zeros-1);
         ans += f(i,j-1,grid,zeros-1);
         ans += f(i,j+1,grid,zeros-1);
        grid[i][j] = 0;
        return ans;
     }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        int zeros= 0;
        int sti,stj;
        cout<<m<<" "<<n <<endl;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1)sti = i,stj = j;
                else if(grid[i][j] != 1)zeros++;
            }
         }
        //  cout<<x<<" "<<y<<" " << sti<<" "<<stj << " "<<endl;
         cout<<zeros<<endl;
        return f(sti,stj,grid,zeros);
        // dfs(grid,sti,stj,zeros);
        return ans;
    }

   
};
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr(m,vector<int>(n));
    for(int i = 0; i<m ;i++){
    for(int j  = 0; j < n;j++)cin>>arr[i][j];
    }
    Solution obj;
    cout<<"paths : " <<obj.uniquePathsIII(arr);
    return 0;
}
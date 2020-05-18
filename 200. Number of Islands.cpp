//Phoneix_RK
/*

https://leetcode.com/problems/number-of-islands/


Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);        
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int count=0;
        /*
        traverse matrix
            if 1 is found 
             1)incr count
             2)do dfs and change all connected 1s to zero
         repeat until no 1 is found
         
         return count
        */
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j);
                }
                    
            }
        }
        return count;
    }
};

//Phoenix-RK

/*

https://leetcode.com/problems/max-area-of-island/


You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

*/



class Solution {
public:
     void findArea(vector<vector<int>>& grid,int i,int j,int& area)
    {
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        area++;
        findArea(grid,i-1,j,area);
        findArea(grid,i+1,j,area);
        findArea(grid,i,j-1,area);
        findArea(grid,i,j+1,area);  
      
        
    }
   
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int area=0,max_area=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    area=0;
                    findArea(grid,i,j,area);
                    max_area=max(area,max_area);
                }
            }
        }
        
        return max_area;
        
    }
};

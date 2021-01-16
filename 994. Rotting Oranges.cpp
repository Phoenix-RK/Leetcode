//Phoenix_RK


/*

https://leetcode.com/problems/rotting-oranges/


You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
       int steps=-1;
       int orange=0;
       queue<pair<int,int>> q; 
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]>0)
                  orange++;
               if(grid[i][j]==2)
                   q.push({i,j});
           }
       }
        
        int x[4]={0,0,-1,1};
        int y[4]={1,-1,0,0};
        
        while(!q.empty())
        {
            steps++;
            int s=q.size();
            
            while(s--)
            {
                pair<int,int> temp=q.front();
                q.pop();
                orange--;
                for(int i=0;i<4;i++)
                {
                    int x_temp = temp.first + x[i];
                    int y_temp = temp.second + y[i];
                    
                    if(x_temp>=0 && x_temp<grid.size() && y_temp>=0 && y_temp<grid[0].size() && grid[x_temp][y_temp]==1)
                    {
                              grid[x_temp][y_temp]=2;
                              q.push({x_temp,y_temp});                             
                    }
                }                
            }
        }
        
        if(orange==0)
            return max(0,steps);//if there are no oranges then steps would be -1 but actual ans should be 0
        return -1;
    }
};

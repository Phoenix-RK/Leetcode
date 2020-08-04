//Phoenix_RK


/*
https://leetcode.com/problems/unique-paths-ii/


Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
[[0,0],[1,1],[0,0]]
Ans: 0
Example 3:
[[0,1,0,0,0],[1,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
Ans: 0

Example 4:
[[1,0]]
Ans: 0


//value in each cell represents in how many ways that cell can be reached from the start.
If an obstacle is present then we cannot get to that partcular cell and we cannot get past that cell along the path.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int a[m][n];
        if(obstacleGrid[0][0]==1)
            return 0;
        int flag=0;
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0]==1)
            {
                a[i][0]=0;
                flag=1;
            } 
            else if(flag==1)
                a[i][0]=0;
            else                
                a[i][0]=1;
        }
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(obstacleGrid[0][i]==1)
            {
                a[0][i]=0;
                flag=1;
            }                
            else if(flag==1)
                a[0][i]=0;
            else
                a[0][i]=1;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    a[i][j]=0;
                else
                    a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
      /*  for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/
        return a[m-1][n-1];
    }
  
    
};

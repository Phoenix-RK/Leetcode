//Phoenix_RK

/*
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/

class Solution {
public:
    
    int uniquePaths(int m, int n) {
     
        //the value in each cell represents in how many ways can the cell be reached from the start
 /*   
         - - -
        |s|1|1|
         - - -    
        |1|2|3|
         - - -
         */
        //the row of the start and the row of the column can be reached only one way - straight - so take this as base case        
        int a[n][m];
        for(int i=0;i<n;i++)        
            a[i][0]=1; //column of the start 
        for(int i=0;i<m;i++)
            a[0][i]=1; //row of the start
      
        //any other cell can be reached through the cell above it and through the cell left to it. Hence no of ways a cell can be reached is the sum of the number of ways the cell left to it reached and the no of ways the cell above it can be reached     
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
       
        
        
        return a[n-1][m-1];
    }
};

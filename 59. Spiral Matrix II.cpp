//Phoenix_RK


/*

https://leetcode.com/problems/spiral-matrix-ii/




Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:

 1 2 3
 8 9 4
 7 6 5

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20

*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
       vector<vector<int>> a(n,vector<int>(n));
      

        int i=1,start_row=0,end_row=n-1,start_col=0,end_col=n-1;
        
        
          while(start_row<=end_row && start_col<=end_col)
          {
              for(int x=start_col;x<=end_col;x++)
                a[start_row][x]=i++;
              
              start_row++;
              
              for(int x=start_row;x<=end_row;x++)
                  a[x][end_col]=i++;
              
              end_col--;
              
              if(start_row<=end_row)
              {
                  for(int x=end_col;x>=start_col;x--)
                      a[end_row][x]=i++;
              }
              
              end_row--;
              
              if(start_col<=end_col)
              {
                  for(int x=end_row;x>=start_row;x--)
                      a[x][start_col]=i++;
              }
              
              start_col++;
          }
                
    return a;
        
    }
};

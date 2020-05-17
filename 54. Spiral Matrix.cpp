//Phoenix_RK
/*

https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
 /*       
        1  2   3   4
        5  6   7   8
        9  10  11  12
        13 14  15  16
   */
        
        vector<int> output;
      

        if(matrix.size() < 1)
            return output;
    
      
        
        int row=matrix.size(),col=matrix[0].size();
        int start_row=0,end_row=row-1,start_col=0,end_col=col-1;
        while(start_row<=end_row && start_col<=end_col)
        {
            for(int i=start_col;i<=end_col;i++)
                output.push_back(matrix[start_row][i]);
            
            start_row++;
            
            for(int i=start_row;i<=end_row;i++)
                output.push_back(matrix[i][end_col]);
            
            end_col--;
            
            if(start_row<=end_row)
            {
                for(int i=end_col;i>=start_col;i--)
                    output.push_back(matrix[end_row][i]);
                end_row--;
            }
            
            if(start_col<=end_col)
            {
                for(int i=end_row;i>=start_row;i--)
                    output.push_back(matrix[i][start_col]);
                start_col++;
                
            }  
            
        }
          return output;            
        
    }
};

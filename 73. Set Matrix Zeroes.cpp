//Phoenix_RK

/*

https://leetcode.com/problems/set-matrix-zeroes/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.


*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        int zero_row_last=-1;
         
        /*
            [
              [1,1,1],
              [1,0,1],
              [1,1,0]
            ] 
        
        */
       // find the last row that has zero 
        for(int i=m-1;i>=0 && zero_row_last==-1 ;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    zero_row_last=i;
                    break;
                }
            }
        }
        if(zero_row_last==-1)
            return ;
        
        // iterate row by row before zero_row_last and for every zero encountered, make matrix[zero_row_last][particular_col]  to zero . This act as a mark 
        for(int i=0;i<zero_row_last ;i++)
        {
            bool zero_row=false;
            
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[zero_row_last][j]=0;
                    zero_row= true;                 
                }
            }
           //make all the elements of the zero row to zero 
            if(zero_row)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        /*
            [
              [1,1,1],
              [0,0,0],
              [1,0,0]
            ] 
        
        */
        
        // using that mark, convert all the elements of the col that are marked to zero
        for(int j=0;j<n;j++)        
        {
            if(matrix[zero_row_last][j]==0)
            {
                for(int i=0;i<m;i++)
                {
                    matrix[i][j]=0;
                }
            }
            
        }
          /*
            [
              [1,0,0],
              [0,0,0],
              [1,0,0]
            ] 
        
        */
        
        //now make the zero_row_last to zero
        for(int j=0;j<n;j++)
        {
            matrix[zero_row_last][j]=0;
        }
        
        /*
            [
              [1,0,0],
              [0,0,0],
              [0,0,0]
            ] 
        
        */
    }
};

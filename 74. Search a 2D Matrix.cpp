//Phoenix_RK

/*

https://leetcode.com/problems/search-a-2d-matrix/


Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
            return false;
        int n=matrix[0].size();
      
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][n-1]<target )
                continue;
            else
            {
                for(int j=0;j<matrix[i].size();j++)
                {
                    if(matrix[i][j]==target)
                        return true;
                }
            }
        }
        return false;
    }
};

//Binary search

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
        if(matrix.size()==0)
            return false;
        
        int r=matrix.size();
        int c=matrix[0].size();
        int left=0,right=r*c-1;
        
        while(left<=right)
        {
             int mid=left+(right-left)/2;
            
             int mid_ele=matrix[mid/c][mid%c];
            
            if(mid_ele==target)
            {
                return true;
            }
            else if(mid_ele<target)
            {
                left=mid+1;
            }
            else if(mid_ele>target)
            {
                right=mid-1;
            }
        
        }
       
        return false;
    }

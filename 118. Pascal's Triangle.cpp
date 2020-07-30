//Phoenix_RK

/*

https://leetcode.com/problems/pascals-triangle/

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/


class Solution {
public:
    
    
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0]=res[rowIndex]=1;
        
        if (rowIndex == 0 || rowIndex==1) 
            return res;
       
        vector<int> prev = getRow(rowIndex-1);
        
        for (int i = 1; i<rowIndex; i++) 
        {  
                res[i] = prev[i-1] + prev[i];
        }
        return res;
    
    }
    vector<vector<int>> generate(int numRows) {
        

       vector<vector<int>> ans;
       
        
        for(int i=0;i<numRows;i++)
        {
            ans.push_back(getRow(i));
        }
        return ans;
    }
};

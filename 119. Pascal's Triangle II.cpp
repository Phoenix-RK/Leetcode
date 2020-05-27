//Phoenix_RK

/*

https://leetcode.com/problems/pascals-triangle-ii/

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

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
};

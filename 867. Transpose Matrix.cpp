//Phoenix_RK
/*

https://leetcode.com/problems/transpose-matrix/


Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

*/
public:
  
    vector<vector<int>> transpose(vector<vector<int>>& A) {
    
    vector<vector<int>> B;
    
       vector<int> temp;
            
            for(int j=0;j<A[0].size();j++)
            {
                
                 for(int i=0;i<A.size();i++)
                 {
                
                     temp.push_back(A[i][j]);
                    
                 }
                B.push_back(temp);
                temp.clear();
            }
        
        return B;
    }
};


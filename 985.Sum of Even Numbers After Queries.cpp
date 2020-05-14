//Phoenix_RK
/*

985. Sum of Even Numbers After Queries
https://leetcode.com/problems/sum-of-even-numbers-after-queries/
Easy

We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.

 

Example 1:

Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]

*/


/**********************************************************************************************
BRUTE FORCE


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        
        int sum;
        vector<int> res;
        for(int i=0;i<queries.size();i++)
        {
            sum=0;
            A[queries[i][1]]=A[queries[i][1]]+queries[i][0];
            
            for(int j=0;j<A.size();j++)
            {
                
                 if(A[j]%2==0)
                    sum+=A[j];
            
            }
          
            res.push_back(sum);
        }
        return res;
    }
};

************************************************************************************************/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        
        int sum=0;
        vector<int> res;
        
        for(auto it:A)
        {
            if(it%2==0)
              sum+=it;
        }
           
        for(int i=0;i<queries.size();i++)
        {
            int index=queries[i][1];
            int val=queries[i][0];
            
         
            if(A[index]%2==0)
               sum-=A[index];
            
            
            A[index]+=val;
            
            if(A[index]%2==0)
                sum+=A[index];
                
          
            res.push_back(sum);
        }
        return res;
    }
};



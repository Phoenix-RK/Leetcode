//Phoenix_RK


/*

https://leetcode.com/problems/maximum-length-of-pair-chain/


You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].




*/

class Solution {
public:
   
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        if(pairs.size()==0)
            return 0;
        
        sort(pairs.begin(),pairs.end());
         
	    int max_pair=-1;
	    vector<int> max_len(pairs.size(),1);
      
        for(int i=1;i<pairs.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1] && max_len[i]<max_len[j]+1)
                {
                    max_len[i]=1+max_len[j];
                                       
                }
            }
             max_pair=max(max_pair,max_len[i]);
        }
        return max_pair;
    }
};

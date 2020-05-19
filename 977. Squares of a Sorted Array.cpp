//Phoenix_RK

/*

https://leetcode.com/problems/squares-of-a-sorted-array/

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        
        for(int i=0;i<A.size();i++)
        {
            res.insert(lower_bound(res.begin(),res.end(),A[i]*A[i]),A[i]*A[i]);
        }
        return res;
    }
};

//Phoenix_RK


/*
https://leetcode.com/problems/maximum-sum-circular-subarray/


Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
*/


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int sum=A[0],max_so_far=A[0],currmax=A[0],min_so_far=A[0],currmin=A[0];
        
        for(int i=1;i<A.size();i++)
        {
            currmax=max(currmax+A[i],A[i]);
            max_so_far=max(max_so_far,currmax);
            currmin=min(currmin+A[i],A[i]);
            min_so_far=min(min_so_far,currmin);
            sum+=A[i];
        }
        
        if(max_so_far<0)
            return max_so_far;
        else
            return max(sum-min_so_far,max_so_far);
    }
};

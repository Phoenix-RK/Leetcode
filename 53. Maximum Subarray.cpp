//Phoenix_RK
/*

https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
      int currmax = nums[0];
     int maxsofar = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            currmax=max(currmax+nums[i],nums[i]);
            maxsofar=max(currmax,maxsofar);
            
        }
        
        return maxsofar;
    }
};



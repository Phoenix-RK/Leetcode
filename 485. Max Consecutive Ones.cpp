//Phoenix_RK

/*

https://leetcode.com/problems/max-consecutive-ones/


Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxones=0,currmax=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]  == 1)
                currmax++;
            
            else
            {
                maxones=max(maxones,currmax);
                currmax=0;
            }
        }
        maxones=max(maxones,currmax);
        return maxones;
    }
};

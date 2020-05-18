//Phoenix_RK

/*

https://leetcode.com/problems/single-number/


Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/


class Solution {
public:
    
    int singleNumber(vector<int>& nums)
    {
        int x=nums[0];
        for(int i=1;i<nums.size();i++)
            x=x^nums[i];
        return x;
    }
};



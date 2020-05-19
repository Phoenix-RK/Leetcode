//Phoenix_RK

/*

https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

Given an array nums of integers, return how many of them contain an even number of digits.


*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int dcount=0;
        int result=0;
        
        for(int i=0;i<nums.size();i++)
        {
            dcount=0;
            int num=nums[i];
            while(num)
            {
                num=num/10;
                dcount++;
            }
            if(dcount%2==0)
                result++;
        }
    
        return result;
        
    }
};

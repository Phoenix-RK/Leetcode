//Phoenix_RK

/*

https://leetcode.com/problems/3sum/


Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105




*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int low=i+1;
                int high = nums.size()-1;
                int target=0-nums[i];
                while(low<high)
                {
                    if(nums[low]+nums[high]==target)
                    {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[low]);
                        res.push_back(nums[high]);
                        ans.push_back(res);

                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[low]+nums[high]>target)
                    {
                        high--;
                    
                        
                    else
                    {
                        low++;
                    }
                }
            }
        }
           return ans;
    }
 //for every number calculate two sum of inner boundary
};

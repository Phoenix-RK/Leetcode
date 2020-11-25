//Phoenix_RK


/*

https://leetcode.com/problems/4sum/


Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []
 

Constraints:

0 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/


class Solution {
public:
     vector<vector<int>> Sum(vector<int>& nums,int target,int start) {
        
        vector<vector<int>> ans;
        
        
        for(int i=start;i<nums.size()-2;i++)
        {
            if(i==start || (i>start && nums[i]!=nums[i-1]))
            {
                int low=i+1;
                int high = nums.size()-1;
                int target1=target-nums[i];
                while(low<high)
                {
                    if(nums[low]+nums[high]==target1)
                    {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[low]);
                        res.push_back(nums[high]);
                        ans.push_back(res);

                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1])high--;
                        low++;
                        high--;
                    }
                    else if(nums[low]+nums[high]>target1)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
           return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
          if(nums.size()<4)
              return result;
        sort(nums.begin(),nums.end());
      
        for(int i=0;i<nums.size()-3;i++)
        {
            vector<vector<int>> temp = Sum(nums,target-nums[i],i+1);
            if(temp.size()!=0)
            {
                for(int j=0;j<temp.size();j++)
                {
                    temp[j].insert(temp[j].begin(),nums[i]);
                     result.push_back(temp[j]);
                }
                        
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
            
        }
        return result;
    }
    
};

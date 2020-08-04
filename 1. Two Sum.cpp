//Phoenix_RK


/*
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

/*
O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j,flag=0;
        vector<int> a;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[j]==target-nums[i])
                {
                    a.push_back(i);
                    a.push_back(j);
                    flag=1;
                    break;
                       
                }                    
                    
            }
            if(flag)
                break;
                
        }         
        
        return a;
    }
};

*/


//O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> a;
        map<int,int> m;
      
        for(i=0;i<nums.size();i++)
        {
                if(m.find(target-nums[i])!=m.end())
                {
                    a.push_back(i);
                    a.push_back(m[target-nums[i]]);
                    return a;
                }       
            m[nums[i]]=i;
        }         
        
        return a;
    }
};



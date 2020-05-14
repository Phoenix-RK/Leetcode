//Phoenix_RK
//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        
        int i,count;
        vector<int> a=nums;
        vector<int> res;
        sort(a.begin(),a.end());
        for(int i=0;i<nums.size();i++)
        {
            count=find(a.begin(),a.end(),nums[i])-a.begin();
            res.push_back(count);
            
        }
        
        return res;
    }
};

//Phoenix_RK


/*


https://leetcode.com/problems/search-in-rotated-sorted-array/



You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4



*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0,high=nums.size()-1;
        int mid=-1;
//locate the lowest value
        while(low<high)
        {
             mid=low+(high-low)/2;
            
            if(nums[mid]>nums[high])
                low=mid+1;
            else 
                high=mid;   
           
        }
        
        int ind=low;//the arr is rotated this much 
        
        low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int act_mid=(mid+ind)%nums.size(); //calc actual mid by using how much times the arr is rotated 
            
            if(nums[act_mid]==target)
                return act_mid;
            else if(nums[act_mid]<target)
                low=mid+1;
            
            else
                high=mid-1;
        }
            
        return -1;
    }
};

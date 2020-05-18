//Phoneix_RK

/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    if(nums.size()==0)
        return 0;
    for(int i=0;i<nums.size()-1;)
    {
        if(nums[i]==nums[i+1])
            nums.erase(nums.begin()+i);
        else
            i++;
     }
        return nums.size();
        
    }
};

//Phoenix_RK
/*


https://leetcode.com/problems/rotate-array/



Given an array, rotate the array to the right by k steps, where k is non-negative.

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*/

class Solution {
public:
    void rot(vector<int>&nums,int l,int r)
    {
        for(int i=l,j=r;i<j;i++,j--)
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();

        if(n<k)
            k=k-n;


           rot(nums,0,n-k-1);
           rot(nums,n-k,n-1);
           rot(nums,0,n-1);
        
    }
};

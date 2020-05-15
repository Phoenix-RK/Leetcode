//Phoenix_RK
/*
https://leetcode.com/problems/move-zeroes/


Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

*/
/*
      0 1 0 3 12
        i j   
        
        1 3 12 0 0
            i
                 j
                 
    ***********************************
        1 0
          i
	  j
        
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int i=0,j=0;
      
        while(i<nums.size() && j<nums.size()-1)
        {
            if(nums[i]==0)
            {
                while(nums[j]==0 && j<nums.size()-1)
                    j++;
                
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                
            }
            i++;
           
            if(j<i)
                j=i;

        }
    }
};

//Phoenix_RK

//https://leetcode.com/problems/next-permutation/

/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
6 2 1 5 4 3 0 -> 6 2 3 0 1 4 5

*/


class Solution {
public:
    void reverse(vector<int>&nums, int i, int j)
    {
        // 6 2 3 5 4 1 0
        //       i     j
        
        while(i<j)
        { 
            int temp=nums[i];
            nums[i] = nums[j];
            nums[j] =  temp;
            i++;
            j--;
        }
    }
    //6 2 1 5 4 3 0
//                k
    void nextPermutation(vector<int>& nums) {
                
        int k=nums.size()-2;
    
      // find the longest decreasing sequence(suffix)
        
        while( k>=0 && nums[k]>=nums[k+1])
        {
            k--;
        }
       
        if(k==-1)
        {
            reverse(nums,0,nums.size()-1);
            return;
        }
       //swap the element that is before the suffix with the element in the suffix which is greater than the element
       //6 2 3 5 4 1 0
       // This results in the prefix (6 2 3) which is greater than the original prefix (6 2 1)
        for(int l=nums.size()-1 ; l>k ;l--)
        {
            if(nums[l]>nums[k])
            {
               int temp = nums[k];
                nums[k] = nums[l];
                nums[l] = temp;
                break;
            }
        }
        //next fix the suffix - since the prefix is greater, suffix has to be smaller,which will make the entire number the next possible permutation
        //so sort the suffix in ascending order (5 4 1 0) -> (0 1 4 5) 
        //since we have found the decreasing suffix in the first step, the suffix will always be in the descending order. Hence just reverse it to find the ascending order.
        
         reverse(nums,k+1,nums.size()-1);
        
    }
};

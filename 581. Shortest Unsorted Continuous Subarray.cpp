//Phoenix_RK

/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.


********************************************************
Sample test cases:
[1,3,8,2,6,3,5,9]
[1,3,8,2,6,5,9]
[2, 6, 4, 8, 10, 9, 15]
[1,2,3,4]
[2,1]

*****************************************************

Find the subarray which is unsorted
1)scan from the left and find the point at which the order collapses
2)scan from the right and the find the point at which the order collapses
3)Find the min and max element in the range of the unsorted subarray
4) Check if every element to the left of the subarray is less than min of the subarray. If not, extend the left range of the subarray to the break point.
5)Check from the right if every element in the right of the subarray is greater than max of the subarray. If not, extend the right range of the subarray to that break point




******************************************************
*/

class Solution {
public:
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    
     int max(int a,int b)
    {
        return a>b?a:b;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        
        int l,r;
        
        int i=1,j=nums.size()-1;
        while(i<nums.size() && nums[i]>=nums[i-1])
            i++;
        
        if(i==nums.size())
            return 0;
        i--;
        while(j>=0 && nums[j]>=nums[j-1])
            j--;
        
      
        
        int min_e=INT_MAX,max_e=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            min_e=min(nums[k],min_e);
            max_e=max(nums[k],max_e);
        }
        
        for(int k=0;k<i;k++)
        {
            if(nums[k]>min_e)
            {
                l=k;
                break;
            }
        }
        
        for(int k=nums.size()-1;k>=j;k--)
        {
            if(nums[k]<max_e)
            {
                r=k;
                break;
            }
        }
      //  cout<<l<<" "<<r<<endl;
        return r-l<0? 0 : r-l+1;
    }
    
};

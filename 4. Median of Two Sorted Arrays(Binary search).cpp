//Phoenix_RK


/*

https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106



*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
 
        if(m>n)
            return  findMedianSortedArrays(nums2,nums1);
    
        int low=0,high=m;
    
        while(low<=high)
        {
            int p1=(low+high)/2;
            int p2= ((m+n+1)/2) - p1;

            int maxleft_a, maxleft_b, minright_a,minright_b;

            if(p1==0)
                maxleft_a=INT_MIN;
            else
                maxleft_a= nums1[p1-1];

            if(p1==m)
                minright_a=INT_MAX;
            else
                minright_a=nums1[p1];


            if(p2==0)
                maxleft_b=INT_MIN;
            else
                maxleft_b= nums2[p2-1];

            if(p2==n)
                minright_b=INT_MAX;
            else
                minright_b=nums2[p2];


            if(maxleft_a<= minright_b && maxleft_b<=minright_a)
            {
                if((m+n)%2==0)
                    return (double)(max(maxleft_a,maxleft_b)+min(minright_a,minright_b))/2;
                else
                    return max(maxleft_a,maxleft_b);
            }
            else if(maxleft_a>minright_b)
                high=p1-1;
            else
                low=p1+1;
        }
        
        return 0;
    }
};

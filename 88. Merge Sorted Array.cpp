//Phoenix_RK
/*

https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

*/

/*
////////////using sort function
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            
        nums1.erase(nums1.begin()+m,nums1.end());
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        nums2.clear();
        
    }
};
*/



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j;
  /*    1 2 3
            j
         2 5 6
             i
    */
    if(m!=0 && n!=0)
    {
        for(int i=n-1;i>=0;i--)
        {
            int last = nums1[m-1];
            for(j= m-2 ; j>=0 && nums1[j]>nums2[i] ; j--) //find the smallest integer in arr1 that is greater than the ith element of arr2
                nums1[j+1]=nums1[j];
            
            if(j!=m-2 || last > nums2[i])
            {
                nums1[j+1]=nums2[i];
                nums2[i]=last;
            }
        }
    }
      /*  
        for(int i=0;i<m;i++)
            cout<<nums1[i]<<" ";
        for(int i=0;i<n;i++)
            cout<<nums2[i]<<" ";
        */
          j= m;
          for(int i=0;i<n;i++)
          {
              nums1[j++]=nums2[i];
              
          }
        
    }
};

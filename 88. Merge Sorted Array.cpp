//Phoenix_RK
/*

https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            
        nums1.erase(nums1.begin()+m,nums1.end());
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        nums2.clear();
        
    }
};

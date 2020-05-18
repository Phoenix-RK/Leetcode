//Phoenix_RK

/*

https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two arrays, write a function to compute their intersection.


*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        auto i1=nums1.begin(),i2=nums2.begin();
        
        while(i1<nums1.end() && i2<nums2.end())
        {
            if(*i1==*i2)
            {
                result.push_back(*i1);
                i1++;
                i2++;
            }
            else if(*i1<*i2)
            {
                *i1++;
            }
            else
                *i2++;
         
         
         }       
        
        return result;        
    }
};


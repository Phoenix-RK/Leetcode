//Phoenix_RK
/*

https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int s=nums.size()/2;
        map<int,int> m;
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            m[*it]++;
            if(m[*it]>s)
                return *it;
        }
        
        return -1;
        
    }
};

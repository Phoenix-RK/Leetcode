//Phoenix_RK
/*
https://leetcode.com/problems/third-maximum-number/

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).



*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
     
        sort(nums.begin(),nums.end());
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            cout<<*it<<" ";
        }
       auto ip= unique(nums.begin(),nums.end()) ;
       nums.resize(distance(nums.begin(),ip));
         for(auto it=nums.begin();it!=nums.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<nums.size()<<" ";
        if(nums.size()<3)
            return nums[nums.size()-1];
            
            
      return nums[nums.size()-3];
    }
};

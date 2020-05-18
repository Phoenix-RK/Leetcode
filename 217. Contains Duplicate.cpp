//Phoenix_RK

/*

https://leetcode.com/problems/contains-duplicate/

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


*/

/*
less optimal

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            
            if(m[*it]>=1)
                return true;
            m[*it]++;
        }    
        return false;           
        
    }
};

*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      
        if(!nums.size())
            return false;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;           
        
    }
};

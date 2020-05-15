//Phoenix_RK
/*

https://leetcode.com/problems/rank-transform-of-an-array/


Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.



Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]

*/


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> dup=arr;
        vector<int>res;
        sort(dup.begin(),dup.end());
        auto end=unique(dup.begin(),dup.end()); 
        //since rank is assigned based on occurance of index ..eliminate duplicates..else rank is skipped by the no of dupliactes 
      
        for(auto it=arr.begin();it!=arr.end();it++)
        {
            int x=lower_bound(dup.begin(),end,*it)-dup.begin();
            res.push_back(x+1);
        }
        
        return res;
    }
};

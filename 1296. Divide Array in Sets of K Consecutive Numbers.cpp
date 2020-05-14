//Phoenix_RK
/*

https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/



Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if its possible otherwise return False.

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6]
*/


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        
        int n=nums.size();
        if(n%k!=0)
            return false;
        
        map<int,int> m;

        for(int i=0;i<nums.size();i++)
            m[nums[i]]=m[nums[i]]+1;
        
        sort(nums.begin(),nums.end());
        int total=0;
        for(int i=0;i<n;i++)
        {
            int elem=nums[i];
            
            if(m[elem]>0 && m[elem-1]==0)
            {
                int l=k;
                while(l>0)
                {
                    if(m[elem]>0)
                        m[elem]--;
                    else
                        return false;
            
                
                    elem++;
                    l--;
                    total++;
                }
            }

        }
        
        return (n==total);
    }
};

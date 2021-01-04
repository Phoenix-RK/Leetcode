//Phoenix_RK


/*

https://leetcode.com/problems/beautiful-arrangement/

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 15



*/

//BACKTRACKING

class Solution {
public:
     int countArrangement(int N) {
        int ans=0;
        vector<int> nums ;
        for (int i=0; i<=N; ++i)
            nums.push_back(i);
        int index=1;
        fix(nums,index,ans);
        return ans;

    }
    void fix(vector<int> nums,int index,int& ans) 
    {
        if (index == nums.size())
        {
            ans++;
            return;
        }
       
        for (int i=index; i<nums.size(); i++) 
        {
            if (nums[i]%index==0 || index%nums[i]==0)
            {
                swap(nums[index],nums[i]);
                fix(nums,index+1,ans);
                swap(nums[i],nums[index]);
            }
        }
        return ;
    }
};


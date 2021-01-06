//Phoenix_RK


/*

https://leetcode.com/problems/most-frequent-subtree-sum/


Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root,int& freq,map<int,int>& m)
    {
        if(!root)
            return 0;
        
        int l = helper(root->left,freq,m);
        int r = helper(root->right,freq,m);
        int sum=l+r+root->val;
       
        m[sum]++;
        freq=max(freq,m[sum]);
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> m;
        vector<int> res;
        if(!root)
            return res;
        int freq=0;
        helper(root,freq,m);
        
        for(auto x:m)
        {
            if(x.second==freq)
                res.push_back(x.first);
        }
        
        return res;
        
        
    }
};



//Phoenix_RK


/*

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

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
   
 bool isSub(TreeNode *T,TreeNode* S)
 {
   
     if(T==NULL && S==NULL)
         return true;
     
     if( T==NULL || S==NULL )
        return false;
     
     return ((T->val==S->val) && isSub(T->left,S->left)&&isSub(T->right,S->right)); 
 }

/*you are required to
complete this function */
bool isSubtree(TreeNode* T, TreeNode* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
    if( S==NULL)
    return true;
    
    if(T==NULL)
        return false;
    
    if(isSub(T,S))
    return true;
    
    
    return (isSubtree(T->left,S)||isSubtree(T->right,S));
}
};

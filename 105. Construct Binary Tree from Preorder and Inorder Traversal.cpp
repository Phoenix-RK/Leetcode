//Phoneix_RK

/**

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

//preorder: 1 2 4 8 9 10 11 5 3 6 7
//inorder: 8 4 10 9 11 2 5 1 6 3 7

/*
			1
		2               3
	4            5       6     7
   8       9  
       10     11

*/
class Solution {
public:
    
    
    TreeNode* construct(int preStart,int inStart,int inEnd,vector<int> preorder,vector<int> inorder)
    {
        if(preStart>preorder.size()-1 || inStart>inEnd)
            return NULL;
        
        TreeNode *root=new  TreeNode(preorder[preStart]);
        
        int index=0;
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inorder[i]==preorder[preStart])
            {
                index=i;
                break;
            }
        }
        
        root->left= construct(preStart+1,inStart,index-1,preorder,inorder);
        root->right= construct(preStart+index-inStart+1,index+1,inEnd,preorder,inorder); //index of root of right subtree can be calculated by omitting all the elements on the left subtree...this can be done by using preorder traversal
//we know that preorder traversal gives the elemnets of left subtree then the right subtree....therefore by calculating the no of elements on the left subtree and adding the no to the index of the root gives the root of right subtree


/*for eg:inorder calc the root of right subtree of 1
preorder

0 1 2 3 4 5   6   7 8 9 10
1 2 4 8 9 10  11  5 3 6  7

inorder
0 1 2  3  4 5 6 7 8 9 10
8 4 10 9 11 2 5 1 6 3  7


prestart=0
instart=0
inend=6

noofele on left= index-instart+1 = 7-0+1=8

8 elements on the left of root of right

add this to curr root index to get the index of root of right subtree
*/      
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(0,0,inorder.size()-1,preorder,inorder);
    }
};

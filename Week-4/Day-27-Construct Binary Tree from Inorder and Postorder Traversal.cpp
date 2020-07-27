Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3403/

/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/


//Solution

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int pstart,int pend)
    {
        if(instart>inend)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pend]);
        int index;
        for(int i=instart;i<=inend;i++)
        {
            if(root->val==inorder[i])
            {
                index=i;
                break;
            }
        }
        root->left=helper(inorder,postorder,instart,index-1,pstart,pstart+index-instart-1);
        root->right=helper(inorder,postorder,index+1,inend,pend+index-inend,pend-1);
        return root;
    }
};
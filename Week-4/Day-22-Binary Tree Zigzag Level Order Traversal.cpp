Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/

/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


*/

//Solution

class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void traverse(TreeNode* root,vector<vector<int>>& ans,int h)
    {
        if(root==NULL)
            return;
        ans[h].push_back(root->val);
        traverse(root->left,ans,h+1);
        traverse(root->right,ans,h+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int h=height(root);
    vector<vector<int>> ans(h);
    traverse(root,ans,0);
    for(int i=0;i<ans.size();i++)
    {
        if(i&1)
            reverse(ans[i].begin(),ans[i].end());
    }       
    return ans;
    }
};
Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/

/*

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

*/

//Solution


class Solution {
public:
    unsigned long dfs(TreeNode* root,unsigned long level,unsigned long order,vector<unsigned long>& start)
    {
        if(root==NULL)
            return 0;
     
        if(start.size()==level)
            start.push_back(order);
      //     cout<<root->val<<"        "<<level<<"              "<<order<<"            "<<start[level]<<"\n";
        unsigned long curr=order+1-start[level];
       unsigned long left=dfs(root->left,level+1,2*order,start);
        unsigned long right=dfs(root->right,level+1,2*order+1,start);
      // cout<<curr<<"   "<<left<<"    "<<right<<"\n";
        return max({curr,left,right});
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned long> start;
       /// vector<int> end;
        return dfs(root,0,1,start);
    }
};
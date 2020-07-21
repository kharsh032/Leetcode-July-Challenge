Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/

/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

//Solution

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int k)
    {
        if(k==word.length()-1)
            return true;
       //char c=board[i][j];
       // cout<<i<<"    "<<j<<"   "<<"boar   "<<board[i][j]<<"    "<<word[k]<<"\n";
        board[i][j]-=65;
        if(i>0&&board[i-1][j]==word[k+1]&&dfs(board,word,i-1,j,k+1))
            return true;
        if(j>0&&board[i][j-1]==word[k+1]&&dfs(board,word,i,j-1,k+1))
            return true;
        if(i<board.size()-1&&board[i+1][j]==word[k+1]&&dfs(board,word,i+1,j,k+1))
            return true;
        if(j<board[0].size()-1&&board[i][j+1]==word[k+1]&&dfs(board,word,i,j+1,k+1))
            return true;
        board[i][j]+=65;
        /// cout<<i<<"    "<<j<<"   "<<"boar   "<<board[i][j]<<"    "<<word[k]<<"\n";
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
                  return true;
            }
        }
        return false;
    }
};
Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3391/

/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/

//SOlution

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int ind=0,start=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                if(start!=0)
                    s[start++]=' ';
                ind=i;
                while(ind<n&&s[ind]!=' ')
                    s[start++]=s[ind++];
                reverse(s.begin()+start-(ind-i),s.begin()+start);
                i=ind;
            }
        }
        return s.substr(0,start);
    }
};
Problem LInk :-https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/

/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

*/


//Solution

class Solution {
public:
    string addBinary(string a, string b) 
    {
        string s="";
        int carry=0,n1=a.size()-1,n2=b.size()-1;
        while(n1>=0||n2>=0||carry==1)
        {
            carry+=(n1>=0)?a[n1--]-'0':0;
            carry+=(n2>=0)?b[n2--]-'0':0;
            s=(carry%2==0?'0':'1')+s;
            carry/=2;
        }
        return s;
    }
};
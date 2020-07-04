Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/

/*

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

//Solution

class Solution {
public:
    int nthUglyNumber(int n) {
     if(n==1)
         return 1;
     vector<int> ans(n);
        ans[0]=1;
    int i=0,j=0,k=0;
     for(int kk=1;kk<n;kk++)
     {
         ans[kk]=min({ans[i]*2,ans[j]*3,ans[k]*5});
         if(ans[kk]==ans[i]*2)
             i++;
         if(ans[kk]==ans[j]*3)
             j++;
         if(ans[kk]==ans[k]*5)
             k++;
     }
    return ans[n-1];
    }
};
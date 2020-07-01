Problem Link :- https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/

/*

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

*/

//Solution

class Solution {
public:
    int arrangeCoins(int n) 
    {
        int left=0,right=n,ans=0;
        long long temp;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            temp=((mid)*(mid+1))/2;
            ///cout<<mid<<"  "<<temp<<"\n";
            if(temp<=n)
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};
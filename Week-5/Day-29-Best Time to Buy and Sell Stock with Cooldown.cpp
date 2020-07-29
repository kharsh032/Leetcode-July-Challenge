Problem LInk :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3405/

/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/



//Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size()<=1)
           return 0;
        int n=prices.size();
       vector<long> buy(n,0),sell(n,0),rest(n,0);
        buy[0]=-prices[0];
        sell[0]=INT_MIN;
        rest[0]=0;
        for(int i=1;i<n;i++)
        {
            rest[i]=max({rest[i-1],sell[i-1]});
            sell[i]=buy[i-1]+prices[i];
            buy[i]=max(buy[i-1],rest[i-1]-prices[i]);
          
            ///cout<<buy[i]<<"    "<<sell[i]<<"    "<<rest[i]<<"\n";
        }
        return max(sell[n-1],rest[n-1]);
    }
};
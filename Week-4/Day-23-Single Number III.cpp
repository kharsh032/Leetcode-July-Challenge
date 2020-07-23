Problem Link :-https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/

/*

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

//Solution

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            xo^=nums[i];
        int x=xo&(~(xo-1));
        int first=0,second=0,i;
        for(i=0;i<n;i++)
        {
            if((x&nums[i])==0)
                first^=nums[i];
            else
                second^=nums[i];
          ///  cout<<(x&nums[i])<<"        ";
       ///  cout<<first<<"   "<<second<<"\n";
        }
       
        return {first,second};
    }
};
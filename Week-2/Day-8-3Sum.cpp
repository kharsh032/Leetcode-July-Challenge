Problem Link :- https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/

/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

//Solution

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3)
            return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
           if(i>0&&nums[i]==nums[i-1])
               continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int curr_sum=nums[left]+nums[right];
                if(nums[i]+curr_sum==0)
                {
                    ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left++]==nums[left]);
                    while(left<right&&nums[right--]==nums[right]);
                }
                else if(nums[i]+curr_sum>0)
                    right--;
                else
                    left++;
                
            }
        }
        return ans;
    }
};
class Solution {
public:
    int rec(vector<int>&nums,int ind,int end,vector<int>&dp)
    {
        if(ind>end)
        {
          return 0;
        }
        if(dp[ind]!=-1)
        return dp[ind];
        int one=rec(nums,ind+1,end,dp);
        int two=nums[ind]+rec(nums,ind+2,end,dp);
        return dp[ind]=max(one,two);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(rec(nums,0,nums.size()-2,dp),rec(nums,1,nums.size()-1,dp2));

    }
};

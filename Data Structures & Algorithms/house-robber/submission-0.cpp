class Solution {
public:
     int rec(vector<int>&nums,int ind,vector<int>&dp)
     {
        if(ind>=nums.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int nottake=rec(nums,ind+1,dp);
        
        int take=nums[ind]+rec(nums,ind+2,dp);
        return dp[ind]=max(take,nottake);



     }
    int rob(vector<int>& nums)
     {
            vector<int>dp(nums.size(),-1);
            return rec(nums,0,dp);
    }
};

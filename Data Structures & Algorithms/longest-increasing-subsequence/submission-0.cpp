class Solution {
public:
int rec(vector<int>&nums,int ind,int prev,vector<vector<int>>&dp)
{
    if(ind==nums.size())
    return 0;
    if(dp[ind][prev+1]!=-1)
    return dp[ind][prev+1];
    int nottake=rec(nums,ind+1,prev,dp);
    int take=0;
    if(prev==-1||nums[ind]>nums[prev])
    take=1+rec(nums,ind+1,ind,dp);
    return dp[ind][prev+1]=max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return rec(nums,0,-1,dp);

    }
};

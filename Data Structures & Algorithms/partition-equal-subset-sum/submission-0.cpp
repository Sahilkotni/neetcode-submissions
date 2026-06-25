class Solution {
public:
bool rec(vector<int>&nums,int ind,int sum,vector<vector<int>>&dp)
{
    if(ind==nums.size()-1)
    {
        return (sum==nums[ind]);
    }
    if(dp[ind][sum]!=-1)
    return dp[ind][sum];
    bool nottake=rec(nums,ind+1,sum,dp);
    bool take=false;
    if(sum>=nums[ind])
    {
        take=rec(nums,ind+1,sum-nums[ind],dp);
    }
    return dp[ind][sum]=take||nottake;
    

}
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2)
        return false;

       vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
       return rec(nums,0,sum/2,dp);    
    }
};

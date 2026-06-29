class Solution {
public:
int rec(vector<int>&nums,int ind,int target,vector<vector<int>>&dp)
{
    if(target==0)
    return 1;
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    int ans=0;
   for(int i=0;i<nums.size();i++)
   {
     
     if(target>=nums[i])
     {
        ans+=rec(nums,i,target-nums[i],dp);
     }
    
   }
    return dp[ind][target]=ans;
    
   
}
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return rec(nums,nums.size()-1,target,dp);    
    }
};
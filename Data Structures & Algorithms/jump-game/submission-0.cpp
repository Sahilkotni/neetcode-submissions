class Solution {
public:
bool rec(vector<int>&nums,int ind,vector<int>&dp)
{
    if(ind>=nums.size()-1)
    return true;
    if(dp[ind]!=-1)
    return dp[ind];
    bool ans=false;
    for(int i=1;i<=nums[ind];i++)
    {
        if(rec(nums,ind+i,dp))
        return dp[ind]=true;
    }
    return dp[ind]=ans;
}
    bool canJump(vector<int>& nums) 
    {
       vector<int>dp(nums.size(),-1);
       return rec(nums,0,dp);    
    }
};

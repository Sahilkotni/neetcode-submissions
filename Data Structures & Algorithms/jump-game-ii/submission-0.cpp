class Solution {
public:
int rec(vector<int>&nums,int ind,vector<int>&dp)
{
    if(ind>=nums.size()-1)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int ans=INT_MAX;
    for(int i=1;i<=nums[ind];i++)
    {
        int k=rec(nums,ind+i,dp);
        if(k!=INT_MAX)
        {
            ans=min(ans,1+k);
        }
    }
    return dp[ind]=ans;

}
    int jump(vector<int>& nums) 
    {
       vector<int>dp(nums.size(),-1);
       return rec(nums,0,dp);    
    }
};

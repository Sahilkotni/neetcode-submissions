class Solution {
public:
int rec(vector<int>&coins,int ind,int amount,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(amount%coins[0]==0)
        {
            return amount/coins[0];
        }
        else
        return INT_MAX;
    }
    if(dp[ind][amount]!=-1)
    return dp[ind][amount];
    int nottake=rec(coins,ind-1,amount,dp);
    int take=INT_MAX;
    if(amount>=coins[ind])
    {
        take=rec(coins,ind,amount-coins[ind],dp);
        if(take!=INT_MAX)
        {
            take=1+take;
        }
    }
    return dp[ind][amount]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) 
    {
        
       vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int ans=rec(coins,coins.size()-1,amount,dp);
       if(ans>=INT_MAX)
       return -1;
       return   ans;  
    }
};

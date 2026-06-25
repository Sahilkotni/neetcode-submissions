class Solution {
public:
    int rec(vector<int>&vc,int ind,int amount,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(amount%vc[ind]==0)
            return 1;
            else
            return 0;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];
        int nottake=rec(vc,ind-1,amount,dp);
        int take=0;
        if(amount>=vc[ind])
        {
            take=rec(vc,ind,amount-vc[ind],dp);

        }
        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins)
     {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return rec(coins,coins.size()-1,amount,dp);    
    }
};

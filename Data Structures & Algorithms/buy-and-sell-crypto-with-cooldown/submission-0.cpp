class Solution {
public:
    int rec(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp)

    {
        if(ind>=prices.size())
        return 0;
        if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy]=max((-prices[ind]+rec(prices,ind+1,0,dp)),rec(prices,ind+1,1,dp));
        }
        else
        {
            return dp[ind][buy]=max((+prices[ind]+rec(prices,ind+2,1,dp)),rec(prices,ind+1,0,dp));
        }
    }
    int maxProfit(vector<int>& prices) 
    {
       vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
       return rec(prices,0,1,dp);    
    }
};

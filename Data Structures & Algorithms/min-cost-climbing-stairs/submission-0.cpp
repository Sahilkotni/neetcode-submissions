class Solution {
public:
int rec(vector<int>&vc,int ind,vector<int>&dp)
{
    if(ind>=vc.size())
    {
        return 0;
    }
    if(dp[ind]!=-1)
    return dp[ind];
    int one=vc[ind]+rec(vc,ind+1,dp);
    
    int two=vc[ind]+rec(vc,ind+2,dp);
    return dp[ind]=min(one,two);
}
    int minCostClimbingStairs(vector<int>& cost) 
    {
       vector<int>dp(cost.size(),-1);
       vector<int>dp1(cost.size(),-1);
       return min(rec(cost,0,dp),rec(cost,1,dp1));    
    }
};

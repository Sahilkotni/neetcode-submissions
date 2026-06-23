class Solution {
public:
  int rec(int n ,vector<int>&dp)
  {
    if(n==0)
    return 1;
    if(dp[n]!=-1)
    return dp[n];
    int one=rec(n-1,dp);
    int two=0;
    if(n>1)
    {
        two=rec(n-2,dp);
    }
    return dp[n]=one+two;
  }
    int climbStairs(int n) 
    {
      vector<int>dp(n+1,-1);
      return rec(n,dp);

    }
};
 
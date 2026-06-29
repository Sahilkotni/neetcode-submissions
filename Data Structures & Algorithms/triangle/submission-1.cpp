class Solution {
public:
const int INF = INT_MAX;


    int rec(vector<vector<int>>&vc,int row,int col,int depth,vector<vector<int>>&dp)
    {
        if(row==depth)
        return vc[row][col];
        if(dp[row][col]!=INF)
        return dp[row][col];
        int bottom=vc[row][col]+rec(vc,row+1,col,depth,dp);
        int diag=vc[row][col]+rec(vc,row+1,col+1,depth,dp);
        return dp[row][col]=min(bottom,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
      vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),INF));
      return rec(triangle,0,0,triangle.size()-1,dp);

    }
};
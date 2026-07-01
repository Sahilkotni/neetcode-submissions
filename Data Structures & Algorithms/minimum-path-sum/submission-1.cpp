class Solution {
public:
int rec(vector<vector<int>>&grid,int row,int col,int m,int n, vector<vector<int>>&dp)
{
    if(row==m&&col==n)
    return grid[row][col];
    if(dp[row][col]!=-1)
    return dp[row][col];
    int right=INT_MAX;
    if(col<n)
    {
        right=rec(grid,row,col+1,m,n,dp)+grid[row][col];
    }
    int down=INT_MAX;
    if(row<m)
    {
       down=rec(grid,row+1,col,m,n,dp)+grid[row][col];
    }
    return dp[row][col]=min(right,down);
}
    int minPathSum(vector<vector<int>>& grid)
     {
         vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
         return rec(grid,0,0,grid.size()-1,grid[0].size()-1,dp);
         
    }
};
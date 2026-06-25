class Solution {
public:
int rec(int row,int col,int m,int n,vector<vector<int>>&dp)
{
    if(row==m&&col==n)
    return 1;
    if(dp[row][col]!=-1)
    return dp[row][col];
    int right=0;
    if(col<n)
    {
        right=rec(row,col+1,m,n,dp);
    }
    int down=0;
    if(row<m)
    {
        down=rec(row+1,col,m,n,dp);
    }
    return dp[row][col]=right+down;
}
    int uniquePaths(int m, int n)
    {
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return rec(0,0,m-1,n-1,dp);    
    }
};

class Solution {
public:
    int rec(vector<vector<int>>&vc,int m,int n,int row,int col,vector<vector<int>>&dp)
    {
        if(vc[m][n]==1)
        return 0;
        if(m==row&&n==col)
        {
            return 1;
        }
        if(dp[m][n]!=-1)
        return dp[m][n];
        int right=0;
        if(n<col)
        {
            right=rec(vc,m,n+1,row,col,dp);
        }
        int down=0;
        if(m<row)
        {
            down=rec(vc,m+1,n,row,col,dp);
        }
        return dp[m][n]=right+down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& vc) 
    {
       vector<vector<int>>dp(vc.size(),vector<int>(vc[0].size(),-1));
       return rec(vc,0,0,vc.size()-1,vc[0].size()-1,dp);    
    }
};
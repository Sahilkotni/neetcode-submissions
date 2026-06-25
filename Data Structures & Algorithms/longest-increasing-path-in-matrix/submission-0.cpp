class Solution {
public:
    int rec(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp)
    {
        if(dp[row][col] != -1)
            return dp[row][col];

        int top = 1, down = 1, left = 1, right = 1;

    
        if(row > 0 && matrix[row-1][col] > matrix[row][col])
            top = 1 + rec(matrix, row-1, col, dp);

        
        if(row < matrix.size()-1 && matrix[row+1][col] > matrix[row][col])
            down = 1 + rec(matrix, row+1, col, dp);

        
        if(col > 0 && matrix[row][col-1] > matrix[row][col])
            left = 1 + rec(matrix, row, col-1, dp);

        
        if(col < matrix[0].size()-1 && matrix[row][col+1] > matrix[row][col])
            right = 1 + rec(matrix, row, col+1, dp);

        return dp[row][col] = max({top, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = max(ans, rec(matrix, i, j, dp));
            }
        }

        return ans;
    }
};
class Solution {
public:
    long long rec(vector<vector<int>>& points, int row, int col,
                  int m, int n,
                  vector<vector<long long>>& dp)
    {
        if(row > m)
            return 0;

        if(dp[row][col] != -1)
            return dp[row][col];

        long long ans = LLONG_MIN;

        for(int i = 0; i < points[0].size(); i++)
        {
            if(row == 0 || col == i)
            {
                ans = max(ans,
                          (long long)points[row][i] +
                          rec(points, row+1, i, m, n, dp));
            }
            else
            {
                ans = max(ans,
                          (long long)points[row][i]
                          - abs(col-i)
                          + rec(points, row+1, i, m, n, dp));
            }
        }

        return dp[row][col] = ans;
    }

    long long maxPoints(vector<vector<int>>& points)
    {
        vector<vector<long long>> dp(
            points.size(),
            vector<long long>(points[0].size(), -1));

        return rec(points, 0, 0,
                   points.size()-1,
                   points[0].size()-1,
                   dp);
    }
};
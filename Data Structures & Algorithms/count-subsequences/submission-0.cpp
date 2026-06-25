class Solution {
public:
    int rec(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
       
        if(j == t.size())
            return 1;

       
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int notTake = rec(s, t, i + 1, j, dp);

        int take = 0;
        if(s[i] == t[j])
            take = rec(s, t, i + 1, j + 1, dp);

        return dp[i][j] = take + notTake;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return rec(s, t, 0, 0, dp);
    }
};
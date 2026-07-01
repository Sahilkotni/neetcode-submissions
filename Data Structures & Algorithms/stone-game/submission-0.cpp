class Solution {
public:
    int rec(vector<int>& piles, int left, int right,
            vector<vector<int>>& dp) {

     
        if (left > right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int takeLeft = piles[left] - rec(piles, left + 1, right, dp);

        int takeRight = piles[right] - rec(piles, left, right - 1, dp);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return rec(piles, 0, n - 1, dp) > 0;
    }
};
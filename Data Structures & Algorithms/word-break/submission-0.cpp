class Solution {
public:
    bool rec(int ind, string &s, vector<string>& wordDict, vector<int>& dp) {
        if (ind == s.size()) return true;

        if (dp[ind] != -1) return dp[ind];

        for (string &word : wordDict) {
            int len = word.size();

            if (ind + len <= s.size() && s.substr(ind, len) == word) {
                if (rec(ind + len, s, wordDict, dp)) {
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return rec(0, s, wordDict, dp);
    }
};
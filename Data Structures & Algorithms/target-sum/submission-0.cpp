class Solution {
public:
    int rec(vector<int>& nums, int ind, int currSum, int target,
            int offset, vector<vector<int>>& dp)
    {
        if (ind == nums.size())
            return currSum == target;

        if (dp[ind][currSum + offset] != -1)
            return dp[ind][currSum + offset];

        int add = rec(nums, ind + 1, currSum + nums[ind], target, offset, dp);
        int sub = rec(nums, ind + 1, currSum - nums[ind], target, offset, dp);

        return dp[ind][currSum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums)
            total += x;

        if (abs(target) > total)
            return 0;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * total + 1, -1));

        return rec(nums, 0, 0, target, total, dp);
    }
};
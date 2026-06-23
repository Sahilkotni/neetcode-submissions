class Solution {
public:
    vector<vector<int>> ans;

    void rec(vector<int>& nums, vector<int>& ds, vector<int>& vis)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ds.push_back(nums[i]);

                rec(nums, ds, vis);

                ds.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> ds;
        vector<int> vis(nums.size(), 0);

        rec(nums, ds, vis);

        return ans;
    }
};
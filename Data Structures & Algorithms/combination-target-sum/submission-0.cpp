class Solution {
public:
 void rec(vector<int>&nums,vector<int>&ds,int ind,int target)

  {
    if(target==0)
    {
        ans.push_back(ds);
        return ;
    }
    if(ind==nums.size())
    {
        if (target==0)
        ans.push_back(ds);
        return ;
    }

    rec(nums,ds,ind+1,target);
    if(nums[ind]<=target)
    {
        ds.push_back(nums[ind]);
        rec(nums,ds,ind,target-nums[ind]);
        ds.pop_back();
    }
  }
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
      vector<int>ds;
      rec(nums,ds,0,target);
      return ans;

    }
};

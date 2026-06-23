class Solution {
public:
  set<vector<int>>ans;
  void rec(vector<int>&nums,int ind,vector<int>ds)
  {
    if(ind==nums.size())
    {
        sort(ds.begin(),ds.end());
        ans.insert(ds);
        return ;

    }
    rec(nums,ind+1,ds);
    ds.push_back(nums[ind]);
    rec(nums,ind+1,ds);
    ds.pop_back();
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
       vector<int>ds;
       rec(nums,0,ds);
      sort(nums.begin(),nums.end());
       vector<vector<int>>ans1(ans.begin(),ans.end());
       return ans1;      
    }
};

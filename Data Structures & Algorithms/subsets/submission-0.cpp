class Solution {
public:
   void rec(vector<int>&nums,vector<int>&ds,int ind)
   {
     if(ind==nums.size())
     {
        ans.push_back(ds);
        return ;
     }
     ds.push_back(nums[ind]);
     rec(nums,ds,ind+1);
     ds.pop_back();
     rec(nums,ds,ind+1);
   }
      vector<vector<int>>ans;    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int>ds;
        rec(nums,ds,0);
        return ans;
      
    }
};

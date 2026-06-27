class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
      if(nums.size()==0)
      return 0;
      sort(nums.begin(),nums.end());
      int count=1;
      int ans=0;
      for(int i=0;i<nums.size()-1;i++)
      {
        if(nums[i]==nums[i+1])
        continue;
         if(nums[i]+1==nums[i+1])
         {
            count++;
            ans=max(ans,count);
         }
         else
         {
            count=1;
         }
      }    
      ans=max(ans,count);
      return ans;
    }
};

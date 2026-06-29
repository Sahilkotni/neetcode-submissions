class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
      sort(nums.begin(),nums.end());
      int ans=0;
      for(int i=nums.size()-1;i>=0;i--)
      {
        int count=1;
        int m=k;
        for(int j=i-1;j>=0;j--)
        {
            if(nums[i]==nums[j])
            {
                count++;
                continue;
            }
            else if(m>=nums[i]-nums[j])
            {
              m-=(nums[i]-nums[j]);
              count++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,count);
      }    
      return ans;
    }
};
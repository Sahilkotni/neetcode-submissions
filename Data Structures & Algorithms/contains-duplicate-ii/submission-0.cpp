class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        vector<pair<int,int>>vc;
        for(int i=0;i<nums.size();i++)
        {
            vc.push_back({nums[i],i});
        }    
        sort(vc.begin(),vc.end());
        for(int i=0;i<vc.size()-1;i++)
        {
          if(vc[i].first==vc[i+1].first && abs(vc[i].second-vc[i+1].second)<=k)
          {
            return true;
          }
        }
        return false;
    }
};
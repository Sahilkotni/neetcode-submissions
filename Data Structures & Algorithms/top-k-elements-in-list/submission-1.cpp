class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
          mp[nums[i]]++;
        }
        vector<pair<int,int>>vc;
        for(auto it:mp)
        {
            vc.push_back({it.second,it.first});
        }
        vector<int>ans;
        sort(vc.begin(),vc.end());
        reverse(vc.begin(),vc.end());
        for(int i=0;i<k;i++)
        {
            ans.push_back(vc[i].second);
        }
        return ans;
        
    }
};

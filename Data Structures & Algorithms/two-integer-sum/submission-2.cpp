class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.first < b.first;
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int,int>> vp;

        for(int i = 0; i < nums.size(); i++)
        {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end(), comp);

        int left = 0;
        int right = vp.size() - 1;
         vector<int>vc;
        while(left < right)
        {
            int sum = vp[left].first + vp[right].first;

            if(sum == target)
            {
              vc=    {vp[left].second, vp[right].second};
              break;
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        sort(vc.begin(),vc.end());
        return vc;
    }
};
class Solution {
public:
    static bool comp(vector<int>vc1,vector<int>vc2)
    {
        if(vc1[0]==vc2[0])
        return vc1[1]<vc2[1];
        return vc1[0]<vc2[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          intervals.push_back(newInterval);
          sort(intervals.begin(),intervals.end(),comp);
          vector<int>ans={intervals[0][0],intervals[0][1]};
          vector<vector<int>>res;
          for(int i=1;i<intervals.size();i++)
          {
            if(ans[1]>=intervals[i][0])
            {
                ans[1]=max(ans[1],intervals[i][1]);

            }
            else
            {
                res.push_back(ans);
                ans[0]=intervals[i][0];
                ans[1]=intervals[i][1];
            }
          }       
          res.push_back(ans);
          return res;
    }
};

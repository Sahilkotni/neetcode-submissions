class Solution {
public:
   static bool comp(vector<int>v1,vector<int>v2)
   {
     return v1[1]<v2[1];
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
           
            int count=0;
            sort(intervals.begin(),intervals.end(),comp);
             vector<int>vc=intervals[0];
            for(int i=1;i<intervals.size();i++)
            {
                if(vc[1]>intervals[i][0])
                {
                    count++;
                    
                }
                else
                {
                    vc=intervals[i];
                }
            }
            return count;

    }
};

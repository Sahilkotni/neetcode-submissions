/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
          vector<int>arr,dep;
          for(int i=0;i<intervals.size();i++)
          {
            arr.push_back(intervals[i].start);
            dep.push_back(intervals[i].end);
          }    
          sort(arr.begin(),arr.end());
          sort(dep.begin(),dep.end());
          int left=0,right=0;
          int count=0;
          int ans=0;
          while(left<arr.size()&&right<dep.size())
          {
            if(arr[left]<dep[right])
            {
                left++;
                count++;
                ans=max(ans,count);

            }
            else
            {
              right++;
              count--;
            }

          }
          return ans;
    }
};

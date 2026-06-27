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
    static bool comp(const Interval &vc1,const Interval &vc2)
    {
        if(vc1.end==vc2.end)
        return vc1.start<vc2.start;
        return vc1.end<vc2.end;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
            sort(intervals.begin(),intervals.end(),comp);
            if(intervals.size() <= 1)
    return true;
            for(int i=0;i<intervals.size()-1;i++)
            {
                if(intervals[i].end>intervals[i+1].start)
                {
                    return false;
                }
            }
            return true;

    }
};

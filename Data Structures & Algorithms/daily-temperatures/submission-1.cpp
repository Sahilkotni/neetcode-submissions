class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
     {
        stack<pair<int,int>>st;
        vector<int>ans(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;i--)
        {
           while(!st.empty()&&st.top().second<=temperatures[i])
           {
            st.pop();
           }
           if(!st.empty())
           {
             ans[i]=(st.top().first-i);
           }
           else
           {
             ans[i]=0;
           }
           st.push({i,temperatures[i]});
        }    
        return ans;
    }
};

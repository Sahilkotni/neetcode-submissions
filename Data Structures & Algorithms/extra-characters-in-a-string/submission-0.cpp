class Solution {
public:
    int rec(string &s,vector<string>&dict,int ind1,vector<int>&dp)
    {
        if(ind1==s.size())
        return 0;
        if(dp[ind1]!=-1)
        return dp[ind1];
        int ans=1+rec(s,dict,ind1+1,dp);
        for(int i=0;i<dict.size();i++)
        {
            if(ind1+dict[i].size()<=s.size()&&s.substr(ind1,dict[i].size())==dict[i])
            ans=min(ans,rec(s,dict,ind1+dict[i].size(),dp));
        }
        return dp[ind1]=ans;

    }
    int minExtraChar(string s, vector<string>& dict) 
    {
           vector<int>dp(s.size(),-1);
           return rec(s,dict,0,dp);
           
    }
};
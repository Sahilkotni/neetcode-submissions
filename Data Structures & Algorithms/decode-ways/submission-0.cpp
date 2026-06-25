class Solution {
public:
  int rec(string &s,int ind,vector<int>&dp)
  {
    
    if(ind==s.size())
    {
        return 1;
    }
    if(s[ind]=='0')
    return 0;

    if(dp[ind]!=-1)
    return dp[ind];
    int one=rec(s,ind+1,dp);
    int two=0;
    if(ind+1<s.size())
    {
       string s1 = "";
      s1 += s[ind];
      s1 += s[ind+1];
        if(stoi(s1)>=10 && stoi(s1)<=26)
        {
            two=rec(s,ind+2,dp);
        }
    }
    return dp[ind]=one+two;
  } 
    int numDecodings(string s) 
    {
       vector<int>dp(s.size(),-1);
       return rec(s,0,dp);    
    }
};

class Solution {
public:
  vector<string>ans;
    void rec(int n,string ds,int open,int close)
    {
      if(ds.size()==2*n)
      {
        ans.push_back(ds);
        return ;
      }
      if(open<n)
      rec(n,ds+'(',open+1,close);
      if(open>close)
      {
        rec(n,ds+')',open,close+1);
      }
    }
    vector<string> generateParenthesis(int n) 
    {
        string ds;
        rec(n,ds,0,0);
        return ans;
    }
};

class Solution {
public:
 vector<string>ans;
   void rec(string &digits,vector<string> &mp,string &ds,int ind)
   {
     if(ind==digits.size())
     {
       ans.push_back(ds);
       return ;
     }
     string letters=mp[digits[ind]-'0'];
     for(char ch:letters)
     {
       ds.push_back(ch);
       rec(digits,mp,ds,ind+1);
       ds.pop_back();
     }
   }
    vector<string> letterCombinations(string digits) 
    {
      if(digits.empty())
        return {};
          vector<string> mp =
        {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        string ds="";
        rec(digits,mp,ds,0);
        return ans;

    }
};

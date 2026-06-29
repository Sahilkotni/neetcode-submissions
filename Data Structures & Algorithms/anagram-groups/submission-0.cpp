class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
   
          vector<string>s1=strs;
       
        for(int i=0;i<strs.size();i++)
        {
            sort(strs[i].begin(),strs[i].end());
        }
        
        map<string,vector<int>>mp;
        for(int i =0;i<strs.size();i++)
        {
           mp[strs[i]].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:mp)
        {
            vector<string>t;
           for(int i=0;i<it.second.size();i++)
           {
             t.push_back(s1[it.second[i]]);
           }
           ans.push_back(t);
        }
        return ans;
    }
};

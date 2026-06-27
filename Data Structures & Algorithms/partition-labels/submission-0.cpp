class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        map<char,int> mp, mp2;
        vector<int> ans;

        for(char ch : s)
            mp[ch]++;

        int lastCut = -1;

        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]--;
            mp2[s[i]]++;

            bool can = true;

            for(auto it : mp2)
            {
                if(mp[it.first] != 0)
                {
                    can = false;
                    break;
                }
            }

            if(can)
            {
                ans.push_back(i - lastCut);
                lastCut = i;
                mp2.clear();
            }
        }

        return ans;
    }
};
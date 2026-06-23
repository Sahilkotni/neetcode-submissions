class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int left=0,right=0;
        map<char,int>mp;
        int maxi=0,ans=0;
        while(right<s.size())
        {
            mp[s[right]]++;
            maxi=max(maxi,mp[s[right]]);
            while((right-left+1)-maxi>k)
            {
              mp[s[left]]--;
              left++;

           maxi = 0;
            for(auto &p : mp)
             maxi = max(maxi, p.second);
            }
            
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};

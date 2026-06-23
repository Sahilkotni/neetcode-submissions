class Solution {
public:
   int caneat(vector<int>&piles,int mid)
   {
     int time=0;
     for(int i=0;i<piles.size();i++)
     {
        time+= (int)ceil((double)piles[i]/(double)mid);
     }
     return time;
   }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
       sort(piles.begin(),piles.end());
       int left=1,right=piles[piles.size()-1];
       int ans=0;
       while(left<=right)
       {
        int mid=left+(right-left)/2;
         if(caneat(piles,mid)<=h)
         {
            ans=mid;
            right=mid-1;
         }
         else
         {
            left=mid+1;
         }
       }    
       return ans;
    }
};

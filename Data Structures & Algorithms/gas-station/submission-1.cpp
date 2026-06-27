class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int cap=0;
        int count=0;
      for(int i=0;i<2*gas.size();i++)
      {
         cap+=gas[(i)%gas.size()]-cost[(i)%gas.size()];
         if(cap>=0)
         {
            count++;
           
         }
         else
         {
            cap=0;
            count=0;
         }
         if(count==gas.size())
         {
             return (i+1)%gas.size();
         }

      }    
      return -1;
    }
};

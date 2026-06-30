class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mp={}
        for i in nums:
            mp[i]=mp.get(i,0)+1

        count=0
        for key,value in mp.items():
             if(value==1):
                return -1
             else:
                count+=(value+2)//3;

        return count    



        
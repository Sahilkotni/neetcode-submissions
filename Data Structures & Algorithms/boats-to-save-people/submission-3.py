class Solution:
    def numRescueBoats(self, nums: List[int], limit: int) -> int:
        nums.sort()
        left=0
        right=len(nums)-1
        count=0
        while(left<=right):
            if(nums[left]+nums[right]<=limit):
                count+=1
                left+=1
                right-=1
            elif(nums[right]<=limit):
                count+=1
                right-=1
            elif(nums[left]<=limit):
                count+=1
                left+=1  

        return count;        
class Solution {
public:
    int findMin(vector<int> &nums) 
    {
       int left=0,right=nums.size()-1;
       int mini=INT_MAX;
       while(left<=right)
       {
         int mid=left+(right-left)/2;
         if(nums[left]<=nums[mid])
         {
                mini=min(nums[left],mini);
                left=mid+1;
         }
         else if(nums[mid]<nums[right])
         {
            mini=min(nums[mid],mini);
            right=mid-1;
         }
       }    
       return mini;

    }
};

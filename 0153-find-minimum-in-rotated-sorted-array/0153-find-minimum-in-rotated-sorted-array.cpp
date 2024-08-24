class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int beg=0,end=n-1;
        int mid;
        
        while(beg<end)
        {
            mid=(beg+end)>>1;
            //if(nums[beg]>nums[end])beg=mid;

            if(nums[mid]<nums[end])end=mid;
            else //if(nums[mid]>=nums[beg])
            {
                beg=mid+1;
            }
        }
        return nums[end];
    }
};
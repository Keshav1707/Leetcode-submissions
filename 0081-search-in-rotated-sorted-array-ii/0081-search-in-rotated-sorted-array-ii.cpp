class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int beg=0;int end=nums.size()-1;
        int mid=0;
        while(beg<=end)
        {
            mid=(beg+end)>>1;
            if(target==nums[mid])return 1;
            if(nums[beg]==nums[mid]&&nums[mid]==nums[end])end--,beg++;
            else if(nums[beg]<=nums[mid])
            {
                if(target>=nums[beg]&&target<nums[mid])end=mid-1;
                else beg=mid+1;
            }
            
            else
            {
                if(target>nums[mid]&&target<=nums[end])
                {
                    beg=mid+1;
                }
                else end=mid-1;
            }
        }
        return 0;
        
    }
};
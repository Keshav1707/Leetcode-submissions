class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0;int end=nums.size()-1;
        int mid=0;
        while(beg<end)
        {
            mid=(beg+end)>>1;
            if(target==nums[mid])return mid;
            else if(nums[beg]<=nums[mid])
            {
                if(target>=nums[beg]&&target<nums[mid])end=mid;
                else beg=mid+1;
            }
            
            else
            {
                if(target>nums[mid]&&target<=nums[end])
                {
                    beg=mid+1;
                }
                else end=mid;
            }
        }
        if(target!=nums[end])return -1;
        return end;
    }
};
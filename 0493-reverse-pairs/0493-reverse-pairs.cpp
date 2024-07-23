    
class Solution {
public:
int x=0;
void merge(long long low,long long high,vector<int>&nums)
{
    long long mid=(low+high)>>1;
    long long size = high-low+1;
        vector<long long> temp(size, 0);
        long long left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        long long m=0;
        for(long long i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
}
    void parts(long long beg,long long end,vector<int>&nums)
    {
        if(beg>=end)return;
        long long mid=(beg+end)>>1;
        parts(beg,mid,nums);
        parts(mid+1,end,nums);
        long long i=beg;
        long long j=mid+1;
        
         while (i <= mid) {
            while (j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            x += (j - (mid + 1));
            i++;
        }
        merge(beg,end,nums);
    }
    int reversePairs(vector<int>& nums) {
        parts(0,nums.size()-1,nums);
        return x;
    }
};
class Solution {
public:
void mergesort(int left,int right,vector<int>&nums)
{
    int mid=(left+right)>>1;
    vector<int> sortedList;
        int indx1 = left, indx2 = mid + 1;
        while (indx1 < mid + 1 && indx2 < right + 1) {
            if (nums[indx1] <= nums[indx2]) {
                sortedList.push_back(nums[indx1++]);
            } else {
                sortedList.push_back(nums[indx2++]);
            }
        }
        while (indx1 < mid + 1) {
            sortedList.push_back(nums[indx1++]);
        }
        while (indx2 < right + 1) {
            sortedList.push_back(nums[indx2++]);
        }
        int indx = left;
        for (auto num : sortedList) {
            nums[indx++] = num;
        }
}
void merge(int beg,int end,vector<int>&nums)
{
    if(beg>=end)return ;
    int mid=(beg+end)>>1;
    merge(beg,mid,nums);
    merge(mid+1,end,nums);
    mergesort(beg,end,nums);
}
    vector<int> sortArray(vector<int>& nums) {
       int n=nums.size();
       merge(0,n-1,nums);
       return nums;
    }
};
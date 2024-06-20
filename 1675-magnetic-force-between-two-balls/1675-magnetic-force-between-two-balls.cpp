class Solution {
public:
bool fun(int mid,vector<int>nums,int m)
{
    int a=1;
    int prev=nums[0];
    
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]-prev>=mid)a++,prev=nums[i];
        if(a>=m)return 1;
    }
    return 0;
}
    int maxDistance(vector<int>& v, int m) {
       sort(v.begin(),v.end());
       int beg=0,end=1e9;
       int mid;
       int ans=0;
       while(beg<=end)
       {
            mid=(beg+end)>>1;
            if(fun(mid,v,m))
            {
                ans=mid;
                beg=mid+1;
            }
            else end=mid-1;
       } 
       return ans;
    }
};
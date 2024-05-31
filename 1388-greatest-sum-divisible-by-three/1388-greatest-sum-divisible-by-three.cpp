class Solution {
public:
int dp[40009][40];
int rec(int ind,int mod,vector<int>&nums)
{
    if(ind>=nums.size())
    {
        if(mod%3==0)return 0;
        else return INT_MIN;
    }
    if(dp[ind][mod]!=-1)return dp[ind][mod];
    int take=nums[ind]+rec(ind+1,(mod+nums[ind])%3,nums);
    int nottake=rec(ind+1,mod,nums);
    return dp[ind][mod]=max(take,nottake);
}
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums);
    }
};
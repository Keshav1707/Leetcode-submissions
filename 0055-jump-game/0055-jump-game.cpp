class Solution {
public:
int dp[10009];
bool rec(int ind,vector<int>&nums)
{
    if(ind==nums.size()-1)
    return true;
    
    if(dp[ind]!=-1)return dp[ind];
    for(int i=1;i<=nums[ind];i++)
    {
        if(rec(ind+i,nums))
        return dp[ind]=true;
    }
    return dp[ind]=0;
}
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
    }
};
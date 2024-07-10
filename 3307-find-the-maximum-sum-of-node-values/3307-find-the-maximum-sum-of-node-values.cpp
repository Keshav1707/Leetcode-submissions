class Solution {
public:
long long dp[20009][2];
long long rec(int ind,vector<int>&nums,bool f,int k)
{
    if(ind==nums.size())
    {
        if(f)return INT_MIN;
        else return 0;
    }
    if(dp[ind][f]!=-1)return dp[ind][f];
    long long dig=nums[ind];
    return dp[ind][f]=max((dig^k)+rec(ind+1,nums,!f,k),dig+rec(ind+1,nums,f,k));
    
} 
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        memset(dp,-1,sizeof(dp));
        return rec(0,nums,0,k);
    }
};
    
  
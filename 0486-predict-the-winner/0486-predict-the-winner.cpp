class Solution {
public:
int dp[30][30];
int rec(int i,int j,vector<int>&nums)
{
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int a=nums[i]+min(rec(i+2,j,nums),rec(i+1,j-1,nums));
    int b=nums[j]+min(rec(i+1,j-1,nums),rec(i,j-2,nums));
    return dp[i][j]=max(a,b);
}
    bool predictTheWinner(vector<int>& nums) {
        int sum=(accumulate(nums.begin(),nums.end(),0));
        memset(dp,-1,sizeof(dp));
        int x=rec(0,nums.size()-1,nums);
        return(x>=(sum-x));
    }
};
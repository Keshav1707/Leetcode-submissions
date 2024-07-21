class Solution {
public:
int dp[1009][59];
int rec(int ind,vector<int>&v,int k)
{
    if(ind==v.size()&&k==0)return 0;
    if(k==0)return 1e9;

    if(dp[ind][k]!=-1)return dp[ind][k];
    int sum=0;
    int parts=INT_MIN;
    int miniSum=INT_MAX;
    for(int i=ind;i<v.size();i++)
    {
        sum+=v[i];
        parts=max(sum,rec(i+1,v,k-1));
        miniSum=min(miniSum,parts);
    }
    return dp[ind][k]=miniSum;
}
    int splitArray(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(0,nums,k);
    }
};
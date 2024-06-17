class Solution {
public:
int dp[2009][4000];
int rec(int ind,int curr,vector<int>&v)
{
    if(ind==v.size())return 0;
    if(dp[ind][curr]!=-1)return dp[ind][curr];
    int nottake=rec(ind+1,curr,v);
    int take=0;
    if(v[ind]>curr)
    {
        take=v[ind]+rec(ind+1,curr+v[ind],v);
    }
    return dp[ind][curr]=max(take,nottake);
}
    int maxTotalReward(vector<int>& v) {
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return rec(0,0,v);
    }
};
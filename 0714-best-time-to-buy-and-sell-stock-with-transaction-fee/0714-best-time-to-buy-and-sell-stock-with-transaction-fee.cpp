class Solution {
public:
int dp[50009][2];
int rec(int ind,bool f,vector<int>&v,int fee)
{
    if(ind==v.size()&&f==0)
    {
        return 0;
    }
    if(ind==v.size())return -1e9;
    if(dp[ind][f]!=-1)return dp[ind][f];
    int nottake=rec(ind+1,f,v,fee);
    int take=-1e9;
    if(f==0)
    {
        take=-v[ind]+rec(ind+1,!f,v,fee);
    }
    else
    {
        take=v[ind]-fee+rec(ind+1,!f,v,fee);
    }
    return dp[ind][f]=max(take,nottake);
}
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices,fee);
    }
};
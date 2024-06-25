class Solution {
public:
int dp[501][501];
int rec(int ind,vector<int>&v,int time)
{
    if(ind==v.size())return 0;
    if(dp[ind][time]!=-1)return dp[ind][time];
    int nottake=rec(ind+1,v,time);
    int take=v[ind]*time+rec(ind+1,v,time+1);
    return dp[ind][time]=max(take,nottake);
}
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return rec(0,v,1);
    }
};
class Solution {
public:
int dp[1009][1009];
int rec(int cur,int copied,int n)
{
    if(cur==n)return 0;
    if(cur>n)return 1e9;
    if(dp[cur][copied]!=-1)return dp[cur][copied];
    return dp[cur][copied]=min(1+rec(cur+copied,copied,n),2+rec(cur+cur,cur,n));
}
    int minSteps(int n) {
        if(n==1)return 0;
        memset(dp,-1,sizeof(dp));
        return rec(1,1,n)+1;
    }
};
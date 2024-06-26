class Solution {
public:
int dp[601][101][101];
int rec(int ind,vector<string>&s,int m,int n)
{
    if(ind==s.size())return 0;
    if(dp[ind][m][n]!=-1)return dp[ind][m][n];
    int nottake=rec(ind+1,s,m,n);
    int take=0;
    int a=0,b=0;
    for(auto i : s[ind])
    {
        if(i=='0')a++;
        else b++;
    }
    if(a<=m&&b<=n)take=1+rec(ind+1,s,m-a,n-b);
    return dp[ind][m][n]=max(take,nottake);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,strs,m,n);
    }
};
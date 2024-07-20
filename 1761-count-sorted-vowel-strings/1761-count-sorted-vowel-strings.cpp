class Solution {
public:
int dp[51][51];
int rec(int ind,int prev,int &n)
{
    if(ind==n)return 1;
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    int a=0;
    for(int i=prev;i<5;i++)
    {
        a+=rec(ind+1,i,n);
    }
    return dp[ind][prev]=a;
}
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n);
    }
};
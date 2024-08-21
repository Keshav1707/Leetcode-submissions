class Solution {
public:
int dp[2009];
const int MOD=1e9+7;
int rec(int ind,string&s)
{
    if(ind==s.size())return 0;
    if(dp[ind]!=-1)return dp[ind];
    vector<int>vis(26,0);
    int a=0;
    for(int j=ind;j<s.size();j++)
    {
        if(vis[s[j]-'a'])continue;
        vis[s[j]-'a']=1;
        a=(a%MOD+(1+rec(j+1,s))%MOD)%MOD;
    }
    return dp[ind]=a;
}
    int distinctSubseqII(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(0,s);
    }
};
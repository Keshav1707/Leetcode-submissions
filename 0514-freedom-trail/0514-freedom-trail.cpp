class Solution {
public:
int dp[200][200];
int rec(int ind,string s,string t,int indb)
{
    if(indb==t.size())return 0;
    int mini=1e9;
    int n=s.size();
    if(dp[ind][indb]!=-1)return dp[ind][indb];
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[indb])
        {
            int a=min(ind,i);
            int b=max(ind,i);
            int c=min(b-a,n-b+a);
            mini=min(mini,1+c+rec(i,s,t,indb+1));
        }
    }
    return dp[ind][indb]=mini;
}
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return rec(0,ring,key,0);
    }
};
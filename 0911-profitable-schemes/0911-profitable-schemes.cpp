class Solution {
public:
int dp[101][101][101];
const int MOD=1e9+7;
int rec(int ind,int pleft,vector<int>&preq,int minprof,int curprof,vector<int>&prof)
{
    if(ind==prof.size())
    {
        if(curprof>=minprof)return 1;
        return 0;
    }
    if(dp[ind][pleft][curprof]!=-1)
    {
        return dp[ind][pleft][curprof];
    }

    int a=rec(ind+1,pleft,preq,minprof,curprof,prof)%MOD;
    
    if(pleft>=preq[ind])
    {
        int newprof=min(minprof,curprof+prof[ind]);
    a=(a%MOD+rec(ind+1,pleft-preq[ind],preq,minprof,newprof,prof)%MOD)%MOD; 
    }

    return dp[ind][pleft][curprof]=a%MOD;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n,group,minProfit,0,profit);
    }
};
       
       

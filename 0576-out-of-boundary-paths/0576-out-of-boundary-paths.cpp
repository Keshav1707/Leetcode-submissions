class Solution {
public:
int dp[60][60][60];
const int mod=1e9+7;
int rec(int cr,int cc,int n,int m,int mxmv)
{
    if(mxmv<0)return 0;
    if(cr<0||cr>=m||cc<0||cc>=n)
    {
        return 1;
    }
    if(dp[cr][cc][mxmv]!=-1)return dp[cr][cc][mxmv];
    long long a=0,b=0,c=0,d=0;
    long long e=0;
    
        a=rec(cr+1,cc,n,m,mxmv-1);
        b=rec(cr-1,cc,n,m,mxmv-1);
        c=rec(cr,cc+1,n,m,mxmv-1);
        d=rec(cr,cc-1,n,m,mxmv-1);
    e=(a+b+c+d)%mod;
    return dp[cr][cc][mxmv]=e;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
       return rec(startRow,startColumn,n,m,maxMove); 
    }
};
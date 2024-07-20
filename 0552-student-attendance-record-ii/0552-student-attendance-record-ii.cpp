const int m=1e9+7;
class Solution {
public:
    int dp[100009][5][5];
    int rec(int n,int absentcnt,int latecnt)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][absentcnt][latecnt]!=-1)return dp[n][absentcnt][latecnt];
        int a=0;
        a+=rec(n-1,absentcnt,0);
        a%=m;
        if(latecnt<2)
        {
            a+=rec(n-1,absentcnt,latecnt+1)%m;
        }
        a%=m;
        if(absentcnt<1)
        {
            a+=rec(n-1,absentcnt+1,0)%m;
        }
        return dp[n][absentcnt][latecnt]=a%m;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n,0,0);
    }
};
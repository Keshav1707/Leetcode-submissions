class Solution {
public:
int dp[1009][1009];
int rec(int i,int j,vector<vector<int>>&v,int m,int n)
{
    
    if(i>=m||j>=n)return 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    int down=rec(i+1,j,v,m,n);
    int right=rec(i,j+1,v,m,n);
    int health=min(down,right);
    if(health==1e9)health=1;
    if(health-v[i][j]>0)return dp[i][j]=health-v[i][j];
    else return dp[i][j]=1;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,0,sizeof(dp));
        int n=dungeon.size();
        int m=dungeon[0].size();
        for(int i=0;i<n;i++)dp[i][m]=1e9;
        for(int j=0;j<m;j++)dp[n][j]=1e9;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                int health=min(right,down);
                if(health==1e9)health=1;
                if(health-dungeon[i][j]>0)dp[i][j]=health-dungeon[i][j];
                else dp[i][j]=1;
            }

        }
        return dp[0][0];
        //return rec(0,0,dungeon,n,m);
    }
};
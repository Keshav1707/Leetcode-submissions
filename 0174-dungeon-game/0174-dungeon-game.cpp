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
        memset(dp,-1,sizeof(dp));
        return rec(0,0,dungeon,dungeon.size(),dungeon[0].size());
    }
};
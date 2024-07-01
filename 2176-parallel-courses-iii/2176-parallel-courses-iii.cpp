class Solution {
public:
int dp[500009];
int dfs(int node,vector<vector<int>>&adj,vector<int>&time)
{
    if(dp[node]!=-1)return dp[node];
    int a=0;
    for(auto i : adj[node])
    {
        a=max(a,dfs(i,adj,time));
        
    }
    return dp[node]=a+time[node-1];
}
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        for(auto i : relations)
        {
            adj[i[0]].push_back(i[1]);
        }
        memset(dp,-1,sizeof(dp));
        
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            int a=0;
            a=dfs(i,adj,time);
            maxi=max(maxi,a);
        }
        return maxi;
    }
};
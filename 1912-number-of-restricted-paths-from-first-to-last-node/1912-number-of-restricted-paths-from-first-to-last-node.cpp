class Solution {
public:
int MOD=1e9+7;
int dp[21000];
int dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&dis)
{
    if(node==1)return 1;
    if(dp[node]!=-1)return dp[node];
    int ans=0;
    for(auto i : adj[node])
    {
        if(dis[i.first]>dis[node])
        {
            ans=(ans%MOD+dfs(i.first,adj,dis)%MOD)%MOD;
        }
    }
    return dp[node]=ans%MOD;
}
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i : edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,n});
        dis[n]=0;
        while(!q.empty())
        {
            int node=q.top().second;
            int dist=q.top().first;
            q.pop();
            for(auto i : adj[node])
            {
                if(dis[i.first]>dist+i.second)
                {
                    dis[i.first]=dist+i.second;
                    q.push({dis[i.first],i.first});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return dfs(n,adj,dis);
    }
};
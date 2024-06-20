class Solution {
public:
int mini=INT_MAX;
void dfs(int node,vector<int>&vis,vector<vector<pair<int,int>>>&adj)
{
    if(vis[node]==1)return;
    vis[node]=1;
    for(auto i : adj[node])
    {
        
            mini=min(mini,i.second);
            dfs(i.first,vis,adj);
        
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i : roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>vis(n+1);
        
        dfs(1,vis,adj);
        return mini;
    }
};
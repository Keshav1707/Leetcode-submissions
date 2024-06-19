class Solution {
public:
void dfs(int node,vector<int>&vis,vector<vector<int>>&adj)
{
    vis[node]=1;
    for(auto i : adj[node])
    {
        if(vis[i]==0)dfs(i,vis,adj);
    }
}
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i : edges)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==0)
            {
                v.push_back(i);
                //dfs(i,vis,adj);
            }
        }
        return v;
    }
};
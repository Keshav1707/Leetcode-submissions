class Solution {
public:
int ans=0;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[node]=1;
    for(auto i : adj[node])
    {
        if(i>0)
        {
            if(vis[i]==0)dfs(i,adj,vis);
        }
        else
        {
            if(vis[abs(i)]==0)ans++,dfs(abs(i),adj,vis);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto i : connections)
        {
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(-i[1]);
        }
        vector<int>vis(n);
        vis[0]=1;
        dfs(0,adj,vis);
        return ans;
    }
};
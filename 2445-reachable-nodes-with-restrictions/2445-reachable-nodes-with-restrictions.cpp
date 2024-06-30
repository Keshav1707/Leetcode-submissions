class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int&c)
{
    vis[node]=1;
    c++;
    for(auto i : adj[node])
    {
        if(vis[i]==0)
        {
            dfs(i,adj,vis,c);
        }
    }
}
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
      vector<vector<int>>adj(n);
      for(auto i : edges)
      {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
      }  
      vector<int>vis(n);
      for(auto i : restricted)
      {
        vis[i]=1;
      }
      int c=0;
      dfs(0,adj,vis,c);
      return c;
    }
};
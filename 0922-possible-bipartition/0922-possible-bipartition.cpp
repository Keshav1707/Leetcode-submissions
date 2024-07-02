class Solution {
public:
bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int col)
{
    vis[node]=col;
    for(auto i : adj[node])
    {
        if(vis[i]==-1)
        {
            if(dfs(i,vis,adj,!col)==0)return 0;
        }
        else if(vis[i]==col)return 0;
    }
    return 1;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(auto i : dislikes)
        {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(i,vis,adj,0)==0)return 0;
                
            }
        }
        return 1;
    }
};
class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>&ans,vector<vector<int>>&adj)
    {
        for(auto i :adj[node])
        {
            if (!ans[i].empty() && ans[i].back() == par)
                continue;
            ans[i].push_back(par);
            dfs(i,par,ans,adj);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i :edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            
            dfs(i,i,ans,adj);
            
        }
        return ans;
    }
};
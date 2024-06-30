class Solution {
public:

long long dfs(long long node,vector<vector<long long>>&adj,vector<long long>&vis,vector<long long>&peoplesdown)
{
    vis[node]=1;
    long long a=1;
    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            
            a+=dfs(i,adj,vis,peoplesdown);  
        }
    }
    
    peoplesdown[node]=a;
    return a;
}
void dfsb(long long node,vector<vector<long long>>&adj,vector<long long>&vis,vector<long long>&peoplesdown,long long seat,long long &litres)
{
    vis[node]=1;
    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            dfsb(i,adj,vis,peoplesdown,seat,litres);
        }
    }
    if(node != 0) {
        litres += (peoplesdown[node] + seat - 1) / seat; 
    }
}

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<long long>>adj(roads.size()+1);
        vector<long long>vis(roads.size()+1);
        for(auto i : roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<long long>v(roads.size()+1);
        dfs(0,adj,vis,v);
        vis=vector<long long>(roads.size()+1);
        long long litres=0;
        dfsb(0,adj,vis,v,seats,litres);
        return litres;
    }
};
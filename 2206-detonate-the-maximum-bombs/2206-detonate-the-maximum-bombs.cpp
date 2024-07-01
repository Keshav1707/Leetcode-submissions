class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int&a)
    {
        vis[node]=1;
        a++;
        for(auto i : adj[node])
        {
            if(!vis[i])dfs(i,vis,adj,a);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>>adj(bombs.size());
        for(int i=0;i<bombs.size();i++)
        {
            for(int j=0;j<bombs.size();j++)
            {
                if(i==j)continue;
                long long a=bombs[i][0],b=bombs[i][1],c=bombs[j][0],d=bombs[j][1],e=bombs[i][2],f=bombs[j][2];
                long long dissqr=abs((a-c)*(a-c))+abs((b-d)*(b-d));
                long long disdim=(e)*(e);
                //cout<<dissqr<<" "<<disdim<<endl;
                if(dissqr<=disdim)adj[i].push_back(j);
            }
        }
        int maxi=0;
        for(int i=0;i<bombs.size();i++)
        {
            vector<int>vis(bombs.size());
            int a=0;
            dfs(i,vis,adj,a);
            maxi=max(maxi,a);
        }
        return maxi;
    }
};
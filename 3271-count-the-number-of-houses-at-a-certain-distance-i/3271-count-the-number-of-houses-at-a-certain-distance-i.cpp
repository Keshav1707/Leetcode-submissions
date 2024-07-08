class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i=0;i<n-1;i++)
        {
            adj[i][i+1]=1;
            adj[i+1][i]=1;
            adj[i][i]=0;
            adj[i+1][i+1]=0;
        }
        if(x!=y)
        {
            adj[x-1][y-1]=1;
            adj[y-1][x-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(j==k)continue;
                    adj[j][k]=min(adj[j][i]+adj[i][k],adj[j][k]);
                }
            }
        }
        vector<int>ans(n);
        for(auto i : adj)
        {
            for(auto j : i)
            {
                if(j==0)continue;
                ans[j-1]++;
            }
            
        }
        return ans;
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       vector<vector<int>>adj(n);
       for(auto i : roads)
       {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
       } 
       int maxi=0;
       for(int i=0;i<n;i++)
       {
            for(int j=i+1;j<n;j++)
            {
                int a=adj[i].size()+adj[j].size();
                for(auto node : adj[i])
                {
                    if(node==j)
                    {
                        a-=1;
                        break;
                    }
                }
                maxi=max(maxi,a);
            }
       }
       return maxi;
    }
};
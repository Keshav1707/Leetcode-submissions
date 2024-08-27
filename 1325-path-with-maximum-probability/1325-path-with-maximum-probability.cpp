class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        int a=0;
        for(auto i : edges)
        {
            adj[i[0]].push_back({i[1],succProb[a]});
            adj[i[1]].push_back({i[0],succProb[a]});
            a++;
        }
        vector<double>dist(n,0.0);
        priority_queue<pair<double,int>,vector<pair<double,int>>>q;
        q.push({1.0,start_node});
        dist[start_node]=1;
        while(!q.empty())
        {
            int node=q.top().second;
            double cost=q.top().first;
            q.pop();
            if(node==end_node)return cost;
            for(auto i : adj[node])
            {
                int inode=i.first;
                double iprob=i.second;
                if(dist[inode]<cost*iprob)
                {
                    dist[inode]=cost*iprob;
                    q.push({dist[inode],inode});
                }
            }
        }
        return 0.00000;
       
    }
};
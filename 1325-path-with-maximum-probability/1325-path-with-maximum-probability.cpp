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
        
        vector<double>dist(n,-1e9);
        queue<pair<int,double>>q;
        q.push({start_node,1});
        dist[start_node]=1;
        while(!q.empty())
        {
            int node=q.front().first;
            //double prob=q.top().second();
            q.pop();
            for(auto i : adj[node])
            {
                int inode=i.first;
                double iprob=i.second;
                //cout<<dist[inode]<<" "<<dist[node]<<" "<<iprob<<endl;
                if(dist[inode]<dist[node]*iprob)
                {
                    //cout<<"a"<<endl;
                    dist[inode]=dist[node]*iprob;
                    q.push({inode,iprob});
                }
            }
        }
        // for(auto i : dist)
        // {
        //     cout<<i<<" ";
        // }
        if(dist[end_node]==-1e9)return 0.0000;
        return dist[end_node];
    }
};
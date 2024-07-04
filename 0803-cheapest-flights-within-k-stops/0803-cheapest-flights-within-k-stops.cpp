class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>>adj(n);
       for(auto i : flights)
       {
            adj[i[0]].push_back({i[1],i[2]});
       } 
       queue<pair<int,pair<int,int>>>pq;
       pq.push({0,{src,0}});
       vector<int>dis(n+1,1e9);
       dis[src]=0;
       while(!pq.empty())
       {
            auto it = pq.front();
            pq.pop();
            int st=it.first;
            int node=it.second.first;
            int dist=it.second.second;
            if(st>k)continue;
            for(auto i : adj[node])
            {
                if(dis[i.first]>dist+i.second&&st<=k)
                {
                    dis[i.first]=dist+i.second;
                    pq.push({st+1,{i.first,dis[i.first]}});
                }
            }
       }
       if(dis[dst]==1e9)return -1;
       return dis[dst];
    }
};
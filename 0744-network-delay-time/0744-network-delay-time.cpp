class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i : times)
        {
            adj[i[0]-1].push_back({i[1]-1,i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n,1e9);
        dis[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto i : adj[node])
            {
                if(dis[i.first]>dist+i.second)
                {
                    dis[i.first]=dist+i.second;
                    pq.push({dis[i.first],i.first});
                }
            }
        }
        int x= *max_element(dis.begin(),dis.end());
        if(x==1e9)return -1;
        return x;
    }
};
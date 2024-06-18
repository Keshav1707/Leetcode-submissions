class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
       vector<vector<pair<int,int>>>adj(n);
       for(auto i : edges)
       {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       vector<int>dis(n,1e9);
       
       dis[0]=0;
       while(!pq.empty())
       {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist>dis[node])continue;
            for(auto i : adj[node])
            {
                if(dist+i.second<dis[i.first]&&dist+i.second<disappear[i.first])
                {
                    dis[i.first]=dist+i.second;
                    pq.push({dist+i.second,i.first});
                }
            }
       }
       for(int i=0;i<n;i++)
       {
        if(dis[i]==1e9)dis[i]=-1;
       }
       return dis;
    }
};
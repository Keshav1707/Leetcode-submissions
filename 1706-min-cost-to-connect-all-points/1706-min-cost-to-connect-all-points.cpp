class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>>adj(points.size());
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                if(i==j)continue;
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dis});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(points.size());
        int ans=0;
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            ans+=wt;
            for(auto it : adj[node])
            {
                if(vis[it.first]==0)pq.push({it.second,it.first});
            }

        }
        return ans;
    }
};
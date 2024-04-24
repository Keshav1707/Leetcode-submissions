class Solution {
public:
const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<long long,long long>>>adj(n);
        for(auto i : roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        set<pair<long long,long long>>s;
        vector<long long>dis(n,LONG_MAX);
        dis[0]=0;
        vector<long long>level(n);
        level[0]=1;
        s.insert({0,0});
        //pq.push({0,k-1});
        while(!s.empty())
        {
            long long node=(*s.begin()).second;
            long long dist=(*s.begin()).first;
            //pq.pop();
            s.erase(s.begin());
            for(auto i : adj[node])
            {
                if(dis[i.first]>dist+i.second)
                {
                    dis[i.first]=dist+i.second;
                    s.insert({dis[i.first],i.first});
                    level[i.first]=level[node];
                }
                else if(dis[i.first]==dist+i.second)level[i.first]=(level[i.first]%MOD+level[node]%MOD)%MOD;
            }
        }
        for(auto i: level)cout<<i<<endl;
        long long x= level[n-1]%MOD;
        //if(x==1e9)return -1;
        return x; 
    }
};
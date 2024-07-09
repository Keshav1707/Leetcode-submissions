class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
      int n=patience.size();
      vector<vector<int>>adj(n);
      for(auto i : edges)
      {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
      }
      queue<int>q;
      q.push(0);
      vector<int>dis(n,-1);
      dis[0]=0;
      while(q.size())
      {
        int node=q.front();
        q.pop();
        for(auto i : adj[node])
        {
            if(dis[i]==-1)
            {
                dis[i]=dis[node]+1;
                q.push(i);
            }
        }
      }
      int ans=0;
      for(int i=1;i<n;i++)
      {
        int msgsent=(dis[i]*2-1)/patience[i];
        int lastmsg=msgsent*patience[i];
        int timeforlast=lastmsg+dis[i]*2;
        ans=max(ans,timeforlast);
        //cout<<i<<" "<<msgsent<<" "<<lastmsg<<" "<<timeforlast<<endl;
      }
      return ans+1;
    }
};
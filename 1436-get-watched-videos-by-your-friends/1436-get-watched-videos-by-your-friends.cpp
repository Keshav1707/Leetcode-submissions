class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
       vector<int>vis(watchedVideos.size());
       vis[id]=1;
       queue<int>q;
       q.push(id);
       int k=0;
       map<string,int>m;
       while(!q.empty())
       {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int node=q.front();
                q.pop();
                if(k==level)
                {
                    for(auto ch : watchedVideos[node])
                    {
                        m[ch]++;
                    }
                }
                else 
                {
                    for(auto i : friends[node])
                    {
                        if(vis[i]==0)
                        {
                            vis[i]=1;
                            q.push(i);
                        }
                    }
                }

            }
            k++;
       } 
       vector<pair<int,string>>v;
       for(auto i : m)
       {
            v.push_back({i.second,i.first});     
       }
       sort(v.begin(),v.end());
       vector<string>va;
       for(auto i : v)
       {
            va.push_back(i.second);
       }
       return va;
    }
};
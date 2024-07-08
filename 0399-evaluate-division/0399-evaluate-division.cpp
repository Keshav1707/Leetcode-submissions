class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>mp;
        int ind=0;
        for(auto i : equations)
        {
            mp[i[0]].push_back({i[1],values[ind]});
            mp[i[1]].push_back({i[0],1/values[ind]});
            ind++;
        }
        vector<double>ans;
        for(auto query : queries)
        {
            queue<pair<string,double>>q;
            q.push({query[0],1});
            if(mp.find(query[0])==mp.end()||mp.find(query[1])==mp.end())
            {
                ans.push_back(-1.0);
                continue;
            }
            if(query[0]==query[1])
            {
                ans.push_back(1.0);
                continue;
            }
            
            string dst=query[1];
            map<string,int>vis;
            vis[query[0]]=1;
            bool f=0;
            while(!q.empty())
            {

                string node=q.front().first;
                double wt=q.front().second;
                if(node==dst)
                {
                    f=1;
                    ans.push_back(wt);
                    break;
                }
                q.pop();
                for(auto i : mp[node])
                {
                    if(vis.find(i.first)==vis.end())
                    {
                        q.push({i.first,wt*i.second});
                        vis[i.first]=1;
                    }
                }
            }
            if(!f)ans.push_back(-1);
        }
        return ans;
    }
};
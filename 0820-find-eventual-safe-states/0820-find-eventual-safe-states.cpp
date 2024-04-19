class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        vector<int>indegree(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            for(auto j:graph[i])
            {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            ans.push_back(n);
            for(auto i:adj[n])
            {
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
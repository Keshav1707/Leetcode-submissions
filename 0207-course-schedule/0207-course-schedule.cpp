class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>>adj(numCourses);
      vector<int>indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }  
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            topo.push_back(n);
            for(auto i : adj[n])
            {
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        if(topo.size()==numCourses)return 1;
        return 0;
    }
};
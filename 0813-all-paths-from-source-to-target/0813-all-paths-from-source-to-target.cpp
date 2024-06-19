class Solution {
public:
void dfs(int start,int end,vector<int>temp,vector<vector<int>>adj,vector<vector<int>>&ans)
{
    temp.push_back(start);
    if(start==end)
    {
        ans.push_back(temp);
        return;
    }
    for(auto i : adj[start])
    {
        dfs(i,end,temp,adj,ans);
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        vector<vector<int>>ans;
        int end=graph.size()-1;
        dfs(0,end,temp,graph,ans);
        return ans;

    }
};
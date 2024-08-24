class Solution {
public:
    void dfs(string node, map<string, vector<string>>& adj, vector<string>& ans) {
        while (!adj[node].empty()) {
            string next = adj[node].front();
            adj[node].erase(adj[node].begin());
            dfs(next, adj, ans);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adj;
        for (auto& i : tickets) {
            adj[i[0]].push_back(i[1]);
        }
        for (auto& [key, val] : adj) {
            sort(val.begin(), val.end());
        }
        
        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

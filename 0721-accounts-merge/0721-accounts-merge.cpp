class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    
    }
    
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string,int>m;
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(m.find(accounts[i][j])==m.end())
                {
                    m[accounts[i][j]]=i;
                }
                else
                {
                    ds.unionBySize(i,m[accounts[i][j]]);
                }
            }
            
        }
        vector<vector<string>>ans(n);
        for(auto i : m)
        {
            string mail=i.first;
            int node=ds.findUPar(i.second);
            ans[node].push_back(mail);
        }
        vector<vector<string>>res;
        for(int i=0;i<n;i++)
        {
            if(ans[i].size()==0)continue;
            sort(ans[i].begin(),ans[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto j : ans[i])
            {
                temp.push_back(j);
            }
            res.push_back(temp);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
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
    int removeStones(vector<vector<int>>& stones) {
        int mr=0,mc=0;
        for(auto i : stones)
        {
            mr=max(mr,i[0]);
            mc=max(mc,i[1]);
        }
        DisjointSet ds(mr+mc+1);
        set<int>s;
        for(auto i : stones)
        {
            int row=i[0];
            int col=i[1]+mr+1;
            ds.unionBySize(row,col);
            s.insert(row);
            s.insert(col);
        }
        int cnt=0;
        for(auto i : s)
        {
            if(ds.findUPar(i)==i)cnt++;
        }
        return stones.size()-cnt;
    }
};
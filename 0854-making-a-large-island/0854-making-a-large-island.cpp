class DisjointSet {
    

public:
vector<int> rank, parent, size;
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
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);
        int dir[5] = {-1, 0, 1, 0, -1};
        int a = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    a++;
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int nr = i + dir[k];
                    int nc = j + dir[k + 1];
                    if (nr >= 0 && nr < n&& nc >=
                            0 && nc < m && grid[nr][nc] == 1) {
                        ds.unionBySize(i * n + j, nr * n + nc);
                    }
                }
            }
        }
        if (a == 0)
            return n * m;
            int maxi=0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0) {
                    int s=1;
                    set<int>st;
                    for (int k = 0; k < 4; k++) 
                    {
                        int nr = i + dir[k];
                        int nc = j + dir[k + 1];
                        if (nr >= 0 && nr < n&& nc >=0 && nc < m && grid[nr][nc] == 1) 
                        {
                            int par=ds.findUPar(nr*n+nc);
                            if(st.find(par)==st.end())
                            {
                                st.insert(par);
                                s+=ds.size[par];
                            }
                            
                        }
                    }
                    maxi=max(maxi,s);
                }
            }
        }
        return maxi;
    }
};
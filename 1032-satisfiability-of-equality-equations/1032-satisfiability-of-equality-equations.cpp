class Solution {
public:
class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto i : equations)
        {
            if(i[1]=='=')
            {
                ds.unionByRank(i[0]-'a',i[3]-'a');
            }
        }
        for(auto i : equations)
        {
            if(i[1]=='!')
            {
                if(ds.findUPar(i[0]-'a')==ds.findUPar(i[3]-'a'))return 0;
            }
        }
        return 1;
    }
};
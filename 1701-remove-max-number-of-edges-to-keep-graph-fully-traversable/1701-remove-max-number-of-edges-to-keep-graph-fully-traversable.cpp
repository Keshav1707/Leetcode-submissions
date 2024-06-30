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

    bool unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return 0;
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
        return 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet dsa(n+1);
        DisjointSet dsb(n+1);
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        int ans=0;
        for(auto i : edges)
        {
            if(i[0]==3)
            {
                
                ans+=dsa.unionByRank(i[1],i[2])|dsb.unionByRank(i[1],i[2]);
                
            }
            else if(i[0]==2)
            {
                
                ans+=dsb.unionByRank(i[1],i[2]);
            }
            else if(i[0]==1)
            {
                ans+=dsa.unionByRank(i[1],i[2]);
            }
        }
        int a=dsa.findUPar(1);
        for(int i=1;i<=n;i++)
        {
            cout<<dsa.findUPar(i)<<endl;
            if(a!=dsa.findUPar(i))return -1;
        }
        int b=dsb.findUPar(1);;
        for(int i=1;i<=n;i++)
        {
            cout<<dsb.findUPar(i)<<endl;
            
            if(b!=dsb.findUPar(i))return -1;
        }
        return edges.size()-ans;
    }
};
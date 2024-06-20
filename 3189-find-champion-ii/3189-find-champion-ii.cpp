class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        for(auto i : edges)
        {
            indegree[i[1]]++;
        }
        int mini=INT_MAX;
        for(auto i : indegree)
        {
            mini=min(i,mini);
        }
        int a=0,ele=-1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==mini)a++,ele=i;
        }
        if(a>1)return -1;
        return ele;
    }
};
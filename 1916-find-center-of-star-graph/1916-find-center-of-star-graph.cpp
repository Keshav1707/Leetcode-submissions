class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>v(edges.size()+2);
        for(auto i : edges)
        {
            v[i[0]]++;
            v[i[1]]++;
            if(v[i[0]]==edges.size())return i[0];
            if(v[i[1]]==edges.size())return i[1];
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>precomp;
        precomp.push_back(0);
        for(auto i : arr)
        {
            precomp.push_back(precomp.back()^i);
        }
        vector<int>ans;
        for(auto i : queries)
        {
            ans.push_back(precomp[i[0]]^precomp[i[1]+1]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>v;
        for(auto i : names)
        {
            v.push_back({0,i});
        }
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            v[i].first=heights[i];
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++)
        {
            names[i]=v[i].second;
        }
        return names;
    }
};
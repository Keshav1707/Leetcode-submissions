class Solution {
public:
void rec(vector<int>&freq,vector<int>&curr,set<vector<int>>&ans,vector<int>&v)
{
    if(curr.size()==v.size())
    {
        ans.insert(curr);
        return ;
    }
    for(int i=0;i<v.size();i++)
    {
        if(freq[i]==0)
        {
            freq[i]=1;
            curr.push_back(v[i]);
            rec(freq,curr,ans,v);
            freq[i]=0;
            curr.pop_back();
        }
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>curr;
        vector<int>freq(nums.size(),0);
        rec(freq,curr,ans,nums);
        vector<vector<int>>ansa;
        for(auto i : ans)ansa.push_back(i);
        return ansa;
    }
};
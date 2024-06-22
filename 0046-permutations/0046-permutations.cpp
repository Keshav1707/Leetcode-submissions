class Solution {
public:
void rec(vector<int>&freq,vector<int>&curr,vector<vector<int>>&ans,vector<int>&v)
{
    if(curr.size()==v.size())
    {
        ans.push_back(curr);
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<int>freq(nums.size(),0);
        rec(freq,curr,ans,nums);
        return ans;
    }
};
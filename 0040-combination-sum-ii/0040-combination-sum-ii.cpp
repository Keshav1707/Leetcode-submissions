class Solution {
public:
void combin(int ind,int target,vector<int>v,vector<int>a,vector<vector<int>>& ans)
{
    if(target == 0)
    {
        ans.push_back(a);
        return ;
    }
    for(int i = ind;i<v.size();i++)
    {
        if(i>ind&&v[i]==v[i-1])continue;
        if(v[i]>target)break;
        a.push_back(v[i]);
        combin(i+1,target-v[i],v,a,ans);
        a.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>a;
        combin(0,target,candidates,a,ans);
        return ans;
    }
};
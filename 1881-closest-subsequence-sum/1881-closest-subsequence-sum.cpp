class Solution {
public:
vector<int>sums(vector<int>v)
{
    int n=v.size();
    long long total = 1 << n;
    vector<int>ans;
    
    for (long long i = 0; i < total; i++) 
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))sum += v[j];
        }
        ans.push_back(sum);
    }
    return ans;
}
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>v,va;
        for(int i=0;i<(n+1)/2;i++)
        {
            v.push_back(nums[i]);
        }
        for(int i=(n+1)/2;i<n;i++)
        {
            va.push_back(nums[i]);
        }

        v=sums(v);
        va=sums(va);
        sort(v.begin(),v.end());
        sort(va.begin(),va.end());
        int mini=INT_MAX;
        for(auto i : v)
        {
            int lb=lower_bound(va.begin(),va.end(),(goal-i))-va.begin();
            if(lb>0)mini=min(mini,abs(goal-va[lb-1]-i));
            if(lb<va.size())mini=min(mini,abs(goal-va[lb]-i));
        }
        return mini;
    }
};
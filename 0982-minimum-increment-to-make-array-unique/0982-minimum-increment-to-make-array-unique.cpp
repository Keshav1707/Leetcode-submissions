class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int>hash(1e6,0);
        for(auto i : nums)
        {
            hash[i]++;
        }
        int ans=0;
        for(auto i : nums)
        {
            int n=i;
            while(hash[i]>1)
            {
                n++;
                if(hash[n]==0)
                {
                    hash[n]++;
                    hash[i]--;
                    ans+=(n-i);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
            if(nums[i]+nums[j]+nums[k]==0)
            {
                ans.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }
            else if(nums[i]+nums[j]+nums[k]>0)
            {
                k--;
            }
            else j++;
            }
        }
        vector<vector<int>>ansa(ans.begin(),ans.end());
        return ansa;
    }
};
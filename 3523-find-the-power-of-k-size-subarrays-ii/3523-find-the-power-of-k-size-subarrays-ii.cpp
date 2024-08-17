class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        int cnt=0;
        int prev=nums[0]-1;
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]==prev+1)cnt++;
            else cnt=1;
            if(cnt==k)
            {
                ans.push_back(nums[i]);
                cnt--;
            }
            else if(i>=k-1) ans.push_back(-1);
            prev=nums[i];
        }
        return ans;
    }
};
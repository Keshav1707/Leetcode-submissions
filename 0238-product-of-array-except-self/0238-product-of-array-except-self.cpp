class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>suf,pre;
       suf.push_back(1);
       suf.push_back(nums[0]);
       for(int i=1;i<nums.size();i++)suf.push_back(suf.back()*nums[i]);
       pre.push_back(1);
       pre.push_back(nums[nums.size()-1]);
       for(int i=nums.size()-2;i>=0;i--)pre.push_back(pre.back()*nums[i]);
       pre.push_back(1);
       suf.push_back(1);
       reverse(pre.begin(),pre.end());
       vector<int>ans;
       for(int i=1;i<nums.size()+1;i++)
       {
            ans.push_back(suf[i-1]*pre[i+1]);
       }
       return ans;
    }
};
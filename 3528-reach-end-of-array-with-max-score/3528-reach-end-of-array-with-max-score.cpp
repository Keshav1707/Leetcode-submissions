class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
       
       long long curr=nums[0];
       long long curele=0;
       long long ans=0;
       for(int i=1;i<nums.size()-1;i++) 
       {
            if(nums[i]>curr)
            {
                ans+=(i-curele)*curr;
                curr=nums[i];
                curele=i;
            }
       }
       ans+=(nums.size()-1-curele)*curr;
       return ans;

    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        for(auto i : nums) {
            if(i == 1) cnt++;
        }
        
        if(cnt == 0) return 0;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) nums.push_back(nums[i]);
        
        int ones = 0, window = 0;
        int mini = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) ones++;
            
            if(i >= cnt) {
                if(nums[i - cnt] == 1) ones--;
            }
            
            if(i >= cnt - 1) {
                mini = min(mini, cnt - ones);
            }
        }
        
        return mini;
    }
};
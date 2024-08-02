class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for (int num : nums) {
            if (num == 1) ones++;
        }
        
        if (ones == 0) return 0;
        
        int n = nums.size();
        int windowOnes = 0;
        
        
        for (int i = 0; i < ones; i++) {
            if (nums[i] == 1) windowOnes++;
        }
        
        int maxOnes = windowOnes;
        
        
        for (int i = ones; i < n + ones; i++) {
            windowOnes -= nums[i - ones];
            windowOnes += nums[i % n];
            maxOnes = max(maxOnes, windowOnes);
        }
        
        return ones - maxOnes;
    }
};
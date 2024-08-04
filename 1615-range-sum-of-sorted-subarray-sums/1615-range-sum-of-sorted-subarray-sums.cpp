class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sum;
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                sum.push_back(current_sum);
            }
        }
        sort(sum.begin(),sum.end());
        int r = 0;
        int MOD = 1e9+7;
        for (int i = left - 1; i < right; ++i) {
            r += sum[i];
            r %= MOD; 
        }
        return r;
    }
};
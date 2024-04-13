class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> v(nums.size(),-1);
        int n=nums.size();
        for (int i = 2*nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[i%n] >= s.top()) {
                s.pop();
            }
            if (s.empty()) {
                s.push(nums[i%n]);
                v[i%n] = -1;
            } 
            else 
            {
                v[i%n] = s.top();
                s.push(nums[i%n]);
            }
        }
        return v;
    }
};
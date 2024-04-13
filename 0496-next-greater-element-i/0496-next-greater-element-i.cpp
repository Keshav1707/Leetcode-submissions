class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> v(nums2.size(),-1);
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] >= s.top()) {
                s.pop();
            }
            if (s.empty()) {
                s.push(nums2[i]);
                v[i] = -1;
            } 
            else 
            {
                v[i] = s.top();
                s.push(nums2[i]);
            }
        }
        map<int,int>m;
        for(int i=0;i<v.size();i++)
        {
            m[nums2[i]]=v[i];
        }
        vector<int>ans;
        for(auto i : nums1)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};
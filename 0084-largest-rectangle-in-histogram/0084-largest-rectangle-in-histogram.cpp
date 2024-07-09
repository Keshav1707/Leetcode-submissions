class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<pair<int, int>> v(heights.size());
        int ind = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (s.empty()) {
                v[ind].first = -1;
            } else {
                v[ind].first = s.top();
            }
            s.push(ind);
            ind++;
        }

        s = stack<int>();
        ind = heights.size() - 1;

        
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (s.empty()) {
                v[ind].second = heights.size();
            } else {
                v[ind].second = s.top();
            }
            s.push(ind);
            ind--;
        }
        int maxi = 0;
        ind = 0;
        for (auto i : v) {
            maxi = max(maxi, (i.second - i.first - 1) * heights[ind]);
            ind++;
        }
        return maxi;
    }
};

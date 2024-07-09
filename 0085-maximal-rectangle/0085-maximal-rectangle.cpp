class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (i == 0)
                    heights[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else
                    heights[i][j] = matrix[i][j] == '1' ? heights[i-1][j] + 1 : 0;
            }
        }
        int maxarea=0;
        for(auto height : heights)
        {
            int n=height.size();
            stack<int>st;
            for(int i=0;i<=n;i++)
            {
                while(!st.empty()&&(i==n||height[st.top()]>=height[i]))
                {
                    int h=height[st.top()];
                    st.pop();
                    int w;
                    if(st.empty())w=i;
                    else w=i-st.top()-1;
                    maxarea=max(maxarea,h*w);
                }
                st.push(i);
            }
        }
        return maxarea;
    }
};
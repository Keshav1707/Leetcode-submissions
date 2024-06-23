class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int>p,pa;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)p.push_back(i+1),pa.push_back(j+1);
            }
        }
        sort(p.begin(),p.end());
        sort(pa.begin(),pa.end());
        
        int a=p.back()-p[0];
        int b=pa.back()-pa[0];
        cout<<a<<" "<<b<<endl;
        return (a+1)*(b+1);
    }
};
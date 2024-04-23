class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>q;
        
        q.push({0,{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        vector<int>direc={-1,0,1,0,-1};
        while(!q.empty())
        {
            int row=q.top().second.first;
            int col=q.top().second.second;
            int dist=q.top().first;
            if(row==n-1&&col==m-1)
            {
                return dist;
            }
            
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+direc[i];
                int ncol=col+direc[i+1];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m)
                {
                    int z=max(dist,abs(grid[row][col]-grid[nrow][ncol]));
                    if(z<dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=z;
                        q.push({z,{nrow,ncol}});
                    }
                    
                    
                }
            }
        }
        return -1;
    }
};
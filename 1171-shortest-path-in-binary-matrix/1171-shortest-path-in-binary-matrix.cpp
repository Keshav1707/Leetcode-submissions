class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{0,0},1});
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
        vector<pair<int,int>>direc={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        vector<int>vis(n*n,0);
        vis[0]=1;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            if(row==n-1&&col==n-1)
            {
                return dis;
            }
            
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nrow=row+direc[i].first;
                int ncol=col+direc[i].second;
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<n&&vis[nrow*n+ncol]==0&&grid[nrow][ncol]==0)
                {
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow*n+ncol]=1;
                }
            }
        }
        return -1;
    }
};
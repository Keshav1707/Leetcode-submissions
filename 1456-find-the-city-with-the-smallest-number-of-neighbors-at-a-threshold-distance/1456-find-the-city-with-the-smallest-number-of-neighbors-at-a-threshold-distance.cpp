class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e8));
        for(auto i: edges)
        {
            adj[i[0]][i[1]]=i[2];
            adj[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }   
            }   
        }
        int mini=INT_MAX,miniele=-1;
        for(int i=0;i<n;i++)
            {
                int a=0;
                for(int j=0;j<n;j++)
                {
                    cout<<adj[i][j]<<" ";
                    if(adj[i][j]<=distanceThreshold)a++;
                }
                cout<<endl;
                //cout<<a<<endl; 
                if(a<=mini)
                {
                    mini=a;
                    miniele=i;
                }  
            }
            return miniele;
    }
};
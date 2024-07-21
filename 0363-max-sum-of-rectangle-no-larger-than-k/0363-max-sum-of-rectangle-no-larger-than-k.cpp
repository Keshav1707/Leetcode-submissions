class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int maxi=-1e9;
        for(int sa=0;sa<m;sa++)
        {
            for(int ea=sa;ea<m;ea++)
            {
                for(int sb=0;sb<n;sb++)
                {
                    int sum=0;
                    for(int eb=sb;eb<n;eb++)
                    {
                        sum+=matrix[eb][ea];
                        if(sa>0)sum-=matrix[eb][sa-1];
                        if(sum<=k)maxi=max(sum,maxi);
                    }
                }
            }
        }
         
        return maxi;
    }
};
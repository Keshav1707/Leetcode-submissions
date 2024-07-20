class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
       int rowsize=colSum.size();
       int colsize=rowSum.size();
       vector<vector<int>>matrix(colsize,vector<int>(rowsize));
        for(int i=0;i<colsize;i++)
        {
            for(int j=0;j<rowsize;j++)
            {
                int minVal=min(rowSum[i],colSum[j]);
                rowSum[i]-=minVal;
                colSum[j]-=minVal;
                matrix[i][j]=minVal;
            }
        }
        return matrix;
    }
};
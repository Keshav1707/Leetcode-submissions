class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>sr,sc;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)sr.insert(i),sc.insert(j);
            }
        }
        for(auto i : sr)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                matrix[i][j]=0;
            }
        }
        for(auto i : sc)
        {
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][i]=0;
            }
        }
    }
};
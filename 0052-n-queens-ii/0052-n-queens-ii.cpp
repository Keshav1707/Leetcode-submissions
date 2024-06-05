class Solution {
public:
bool canplace(int row,int col,vector<string>v)
    {
        int r=row,c=col;
        while(c--&&r--)
        {
            if(v[r][c]=='Q')return 0;
        }
        r=row,c=col;
        while(c--)
        {
            if(v[r][c]=='Q')return 0;

        }
        r=row,c=col;
        while(r<v.size()&&c>=0)
        {
            if(v[r][c]=='Q')return 0;
            r++;
            c--;
        }
        return 1;
    }
    int rec(int col,vector<string>&v,int n)
    {
        if(col==n)
        {
            return 1;
        }
        int a=0;
        for(int i=0;i<n;i++)
        {
            if(canplace(i,col,v))
            {
                v[i][col]='Q';
                a+=rec(col+1,v,n);
                v[i][col]='.';
            }
        }
        return a;
    }
    int totalNQueens(int n) {
        vector<string>v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i]+='.';
            }
        }
        return rec(0,v,n);
    }
};
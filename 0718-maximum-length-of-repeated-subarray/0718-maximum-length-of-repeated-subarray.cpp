class Solution {
public:
int dp[2000][2000];
int rec(int a,int b,vector<int>&va,vector<int>&vb,int&f)
{
    if(a==va.size()||b==vb.size())
    {
        return 0;
    }
    if(dp[a][b]!=-1)return dp[a][b];
    int x=0;

    rec(a+1,b,va,vb,f);
    rec(a,b+1,va,vb,f);
    if(va[a]==vb[b])x=1+rec(a+1,b+1,va,vb,f);
    f=max(f,x);
    
    return dp[a][b]=x;

}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int f=0;
        rec(0,0,nums1,nums2,f);
        return f;
    }
};
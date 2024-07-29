class Solution {
public:
int dp[1009][1009][4];
int dpa[1009][1009][4];
int reca(int ind,int pind,int k,vector<int>&v)
{
    if(k==0)return 1;
    if(ind==v.size())return 0;
    if(dp[ind][pind+1][k]!=-1)return dp[ind][pind+1][k];
    int pick=0,npick=0;
    npick=reca(ind+1,pind,k,v);
    if(pind==-1||(k>0&&v[pind]>v[ind]))
    {
        pick=reca(ind+1,ind,k-1,v);

    }
    return dp[ind][pind+1][k]=pick+npick;
}
int rec(int ind,int pind,int k,vector<int>&v)
{
    if(k==0)return 1;
    if(ind==v.size())return 0;
    if(dpa[ind][pind+1][k]!=-1)return dpa[ind][pind+1][k];
    int pick=0,npick=0;
    npick=rec(ind+1,pind,k,v);
    if(pind==-1||(k>0&&v[pind]<v[ind]))
    {
        pick=rec(ind+1,ind,k-1,v);

    }
    return dpa[ind][pind+1][k]=pick+npick;
}
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        memset(dpa,-1,sizeof(dpa));
        return rec(0,-1,3,rating)+reca(0,-1,3,rating);
    }
};
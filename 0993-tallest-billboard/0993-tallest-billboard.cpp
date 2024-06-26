class Solution {
public:
int maxi=0;
int dp[21][10001];
int rec(int ind,vector<int>&v,int diff)
{
    if(ind==v.size())
    {
        if(diff==0)return 0;
        return INT_MIN;
    }
    if(dp[ind][diff+5000]!=-1)return dp[ind][diff+5000];
    int a=rec(ind+1,v,diff);
    int b=v[ind]+rec(ind+1,v,diff+v[ind]);
    int c=v[ind]+rec(ind+1,v,diff-v[ind]);

    return dp[ind][diff+5000]=max({a,b,c});
}
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp,-1,sizeof(dp));
        return rec(0,rods,0)/2;
        
    }
};
class Solution {
public:
int dp[100005][2];
int rec(int ind,int preva,int prevb,vector<int>&va,vector<int>&vb,bool sw)
{
    if(ind==va.size())return 0;
    if(dp[ind][sw]!=-1)return dp[ind][sw];
    int swap=INT_MAX,notswap=INT_MAX;
    if(va[ind]>preva&&vb[ind]>prevb)
    {
        notswap=rec(ind+1,va[ind],vb[ind],va,vb,0);
    }
    if(va[ind]>prevb&&vb[ind]>preva)
    {
    swap=1+rec(ind+1,vb[ind],va[ind],va,vb,1);
    }
    return dp[ind][sw]=min(swap,notswap);
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,-1,-1,nums1,nums2,0);
    }
};
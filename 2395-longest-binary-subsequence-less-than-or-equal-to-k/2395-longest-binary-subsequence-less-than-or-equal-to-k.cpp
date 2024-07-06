class Solution {
public:
int dp[1009][1009];
int rec(int ind,int cnt,int a,string&s,int&k)
{
    
    if(ind<0)return 0;
    if(dp[ind][cnt]!=-1)return dp[ind][cnt];
    int pick=0,notpick=0;
    notpick=rec(ind-1,cnt,a,s,k);
    int num=s[ind]-'0';
    if((a+num*pow(2,cnt))<=k)
    {
        
        pick=1+rec(ind-1,cnt+1,(a+num*pow(2,cnt)),s,k);
    }
    
    return dp[ind][cnt]=max(pick,notpick);
}
    int longestSubsequence(string s, int k) {
        
        memset(dp,-1,sizeof(dp));
        int n=s.size()-1;
        return rec(n,0,0,s,k);
        
    }
};
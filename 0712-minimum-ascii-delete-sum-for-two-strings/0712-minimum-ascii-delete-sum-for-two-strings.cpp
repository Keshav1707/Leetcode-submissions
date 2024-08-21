class Solution {
public:
int dp[1009][1009];
int rec(int inda,int indb,string&s1,string&s2)
{
    if(inda==s1.size()||indb==s2.size())return 0;
    if(dp[inda][indb]!=-1)return dp[inda][indb];
    int a=0,b=0,c=0;
    a=rec(inda+1,indb,s1,s2);
    b=rec(inda,indb+1,s1,s2);
    if(s1[inda]==s2[indb])c=2*(int)(s1[inda])+rec(inda+1,indb+1,s1,s2);
    return dp[inda][indb]=max({a,b,c});

}
    int minimumDeleteSum(string s1, string s2) {
        int sum=0;
        for(auto i :s1)sum+=(int)i;
        for(auto i :s2)sum+=(int)i;
        memset(dp,-1,sizeof(dp));
        return sum-rec(0,0,s1,s2);
    }
};
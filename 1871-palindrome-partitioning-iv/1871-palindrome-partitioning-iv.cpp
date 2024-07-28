class Solution {
public:
int dp[2009][4];
bool ispal(int str,int end,string&s)
{
    while(str<end)
    {
        if(s[str]!=s[end])return 0;
        str++;
        end--;
    }
    return 1;
}
bool rec(int ind, int k, string&s)
    {
        if(ind==s.size()&&k==0)return 1;
        
        if(dp[ind][k]!=-1)return dp[ind][k];
        
        int n=s.size();
        bool a=0;
        for(int i=ind;i<n;i++)
        {
            if(k>0&&ispal(ind,i,s))
            {
                a=a|rec(i+1,k-1,s);
            }
        }
        return dp[ind][k]=a;
    }
    bool checkPartitioning(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(0,3,s);
    }
};
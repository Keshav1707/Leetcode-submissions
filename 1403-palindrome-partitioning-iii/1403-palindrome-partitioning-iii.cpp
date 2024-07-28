class Solution {
public:
int dp[109][109];
    int ispal(int i,int j,string&s)
    {
        int a=0;
        while(i<j)
        {
            if(s[i]!=s[j])a++;
            i++;
            j--;
        }
        return a;
    }
    int rec(int ind, int k, string&s)
    {
        if(ind==s.size()&&k==0)return 0;
        
        if(dp[ind][k]!=-1)return dp[ind][k];
        int a=1e9;
        int n=s.size();
        
        for(int i=ind;i<n;i++)
        {
            int x=ispal(ind,i,s);
            if(k>0)
            a=min(a,x+rec(i+1,k-1,s));
        }
        return dp[ind][k]=a;
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(0,k,s);
    }
};
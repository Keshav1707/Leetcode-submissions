class Solution {
public:
int dp[105][105];
int rec(int ind,int pind,vector<string>&v)
{
    if(ind==v[0].size())return 0;
    if(dp[ind][pind+1]!=-1)return dp[ind][pind+1];
    int take=INT_MAX,nottake=INT_MAX;
    nottake=1+rec(ind+1,pind,v);
    
    if(pind==-1)
    {
        take=rec(ind+1,ind,v);
    }
    else
    {
        bool f=0;
        for(int j=0;j<v.size();j++)
        {
            
            if(v[j][ind]<v[j][pind])
            {
                f=1;
                break;
            }
        }
        if(!f)take=rec(ind+1,ind,v);
    }
    return dp[ind][pind+1]=min(take,nottake);
}
    int minDeletionSize(vector<string>& strs) {
        memset(dp,-1,sizeof(dp));
        return rec(0,-1,strs);
    }
};
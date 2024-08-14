class Solution {
public:
int dp[109][109];
    bool rec(int ind,int a,string s)
    {
        if(ind==s.size())
        {
            if(a==0)return true;
            else return false;
        }
        if(a<0)return false;
        bool f=0;
        if(dp[ind][a]!=-1)return dp[ind][a];
        if(s[ind]=='(')f=f|rec(ind+1,a+1,s);
        if(s[ind]==')')f=f|rec(ind+1,a-1,s);
        if(s[ind]=='*')f=f|rec(ind+1,a+1,s)|rec(ind+1,a-1,s)|rec(ind+1,a,s);
        return dp[ind][a]=f;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
       return rec(0,0,s);
    }
};
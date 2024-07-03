class Solution {
public:
vector<vector<int>>dp;
bool rec(int inda,int indb,string&s,string&p)
{
    if(dp[inda][indb]!=-1)return dp[inda][indb];
    if(inda==s.size()&&indb==p.size())return dp[inda][indb]=1;
    if(indb==p.size()&&inda<s.size())return dp[inda][indb]=0;
    if(inda==s.size())
    {
        for(int i=indb;i<p.size();i++)
        {
            if(p[i]!='*')return dp[inda][indb]=false;
        }
        return dp[inda][indb]=true;
    }
    if(s[inda]==p[indb]||p[indb]=='?')return dp[inda][indb]=rec(inda+1,indb+1,s,p);
    else if(p[indb]=='*')return dp[inda][indb]= rec(inda+1,indb,s,p)||rec(inda,indb+1,s,p);
    return dp[inda][indb]=0;
}
        
       
    bool isMatch(string s, string p) {
       dp=vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
     return rec(0,0,s,p);
    }
};
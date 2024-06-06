class Solution {
public:
int dp[1009];
bool rec(int ind,string s,vector<string>&v)
{
    if(ind==s.size())return 1;
    if(dp[ind]!=-1)return dp[ind];
    bool a=0;
    for(auto j : v)
        {
            if(j==s.substr(ind,j.size()))
            {
                //cout<<j<<" "<<s.substr(ind,j.size())<<endl;
                a=a|rec(ind+j.size(),s,v);
            }
        }
    return dp[ind]=a;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        return rec(0,s,wordDict);
    }
};
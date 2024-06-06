class Solution {
public:
void rec(int ind,string s,vector<string>&v,string temp,vector<string>&ans)
{
    if(ind==s.size())
    {
        temp.pop_back();
        ans.push_back(temp);
        return ;
    }
    //if(dp[ind]!=-1)return dp[ind];
    //bool a=0;
    for(auto j : v)
        {
            if(j==s.substr(ind,j.size()))
            {
                //cout<<j<<" "<<s.substr(ind,j.size())<<endl;
                temp+=j+" ";
                //a=a|
                rec(ind+j.size(),s,v,temp,ans);
                int a=j.size()+1;
                while(a--)
                {
                    temp.pop_back();
                }
            }
        }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        rec(0,s,wordDict,"",ans);
        return ans;
    }
};
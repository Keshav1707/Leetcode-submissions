class Solution {
public:

vector<int> rec(int i,int j,string&s)
{
    if(j-i+1<=2)
    {
        //cout<<stoi(s.substr(i,j-i+1))<<" ";
        return {stoi(s.substr(i,j-i+1))};
    }
    vector<int>ans;
    for(int k=i;k<j;k++)
    {
        if(isdigit(s[k])==0)
        {
            vector<int>ansa=rec(i,k-1,s);
            vector<int>ansb=rec(k+1,j,s);
            for(auto i : ansa)
            {
                for(auto j:ansb)
                {
                    if(s[k]=='+')
                    {
                        ans.push_back(i+j);
                    }
                    if(s[k]=='-')
                    {
                        ans.push_back(i-j);
                    }
                    if(s[k]=='*')
                    {
                        ans.push_back(i*j);
                    }
                }
            }
        }
    }
    return ans;
}
    vector<int> diffWaysToCompute(string s) {
        
        return rec(0,s.size()-1,s);
    }
};
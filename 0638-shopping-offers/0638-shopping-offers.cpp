class Solution {
public:
unordered_map<string,int>mp;
int rec(int ind,vector<int>&c,vector<vector<int>>&sp,vector<int>need)
{
    if(ind==sp.size())
    {
        int cost=0;
        for(int i=0;i<c.size();i++)
        {
            cost+=need[i]*c[i];
        }
        return cost;
    }
    string s=to_string(ind);
    for(auto i : need)s+=to_string(i);
    if(mp.find(s)!=mp.end())return mp[s];
    vector<int>temp=need;
    int nottake=rec(ind+1,c,sp,need);
    int x=sp[ind].back();
    bool f=1;
    for(int i=0;i<c.size();i++)
    {
        if(temp[i]<sp[ind][i])
        {
            f=0;
            break;
        }
        temp[i]-=sp[ind][i];
        
    }
    int take=INT_MAX;
    if(f)take=x+rec(ind,c,sp,temp); 
    return mp[s]=min(take,nottake);
}
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return rec(0,price,special,needs);
    }
};

     
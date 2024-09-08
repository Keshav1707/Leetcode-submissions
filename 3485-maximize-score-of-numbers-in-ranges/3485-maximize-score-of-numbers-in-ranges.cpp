class Solution {
public:
bool possible(int mid,vector<int>&v,int d)
{
    long long prev=v[0];
    for(int i=1;i<v.size();i++)
    {
        long long next=max(prev+mid,v[i]*1LL);
        if(next>v[i]+d)return 0;
        prev=next;
    }
    return true;
}
    int maxPossibleScore(vector<int>& start, int d) 
    {
        
        sort(start.begin(),start.end());
        long long lo=0,hi=start.back()+d,mid;
        long long ans=0;
        while(lo<=hi)
        {
            mid=(hi+lo)>>1;
            if(possible(mid,start,d))ans=mid,lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
};
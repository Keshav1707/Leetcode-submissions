class Solution {
public:
bool fun(vector<int>v,int m,int k,int mid)
{
    int a=0,b=0;
    for(auto i : v)
    {
        if(i<=mid)a++;
        else a=0;
        if(a==k)b++,a=0;
    }
    if(b>=m)return 1;
    else return 0;
}
    int minDays(vector<int>& v, int m, int k) {
        int beg=0,end=*max_element(v.begin(),v.end());
        int mid;
        while(beg<end)
        {
            mid=(beg+end)>>1;
            if(fun(v,m,k,mid))
            {
                end=mid;
            }
            else beg=mid+1;
        }
        if(fun(v,m,k,end))
        return end;
        return -1;
    }
};
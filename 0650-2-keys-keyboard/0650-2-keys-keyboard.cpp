class Solution {
public:
int rec(int cur,int copied,int n)
{
    if(cur==n)
    {
        return 0;
    }
    if(cur>n)return 1e9;
    return min(1+rec(cur+copied,copied,n),2+rec(cur+cur,cur,n));
}
    int minSteps(int n) {
        if(n==1)return 0;
        return rec(1,1,n)+1;
    }
};
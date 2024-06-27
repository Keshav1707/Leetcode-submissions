class Solution {
public:
const int MOD=1e9+7;
int binpow(long long a,long long b)
{
    if(b==0)return 1;
    long long res=binpow(a,b/2);
    if(b&1)return (a%MOD*res%MOD*res%MOD)%MOD;
    else return (res%MOD*res%MOD)%MOD;
}
    int countGoodNumbers(long long n) {
       long long even=binpow(20,n/2)%MOD;
       if(n&1)even*=5;
       return (even)%MOD;
    }
};
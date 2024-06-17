class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++)
        {
            long long x=c-i*i;
            long long m=sqrt(x);
            if(m*m==x)return 1;
        }
        return 0;
    }
};
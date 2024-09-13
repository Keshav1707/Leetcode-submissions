class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long>dp(n+1),va(primes.size());
        dp[0]=1;
        int sum=1;
        for(int j=0;j<n;j++)
        {
            int mini=INT_MAX;
            for(int i=0;i<primes.size();i++)
            {
                if(mini>primes[i]*dp[va[i]])
                {
                    mini=primes[i]*dp[va[i]];
                    
                    
                }
            }
            for(int i=0;i<primes.size();i++)
            {
                if(mini==primes[i]*dp[va[i]])
                {
                    va[i]++;
                }
            }
            
            dp[j+1]=(mini);
            
        }
        return dp[n-1];
    }
};
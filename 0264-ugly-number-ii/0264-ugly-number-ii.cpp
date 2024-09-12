class Solution {
public:
    int nthUglyNumber(int n) {
        int a=0,b=0,c=0;
        vector<int>dp;
        dp.push_back(1);
        for(int i=1;i<n;i++)
        {
            int mini=min({2*dp[a],3*dp[b],5*dp[c]});
            dp.push_back(mini);
            if(mini==2*dp[a])a++;
            if(mini==3*dp[b])b++;
            if(mini==5*dp[c])c++;
        }
        for(auto i : dp)
        {
            cout<<i<<endl;
        }
        return dp[n-1];
    }
};
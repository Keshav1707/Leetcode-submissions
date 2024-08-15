class Solution {
public:
int dp[50009][2];
int rec(int ind,bool f,vector<int>&v,int fee)
{
    if(ind==v.size()&&f==0)
    {
        return 0;
    }
    if(ind==v.size())return -1e9;
    if(dp[ind][f]!=-1)return dp[ind][f];
    int nottake=rec(ind+1,f,v,fee);
    int take=-1e9;
    
    return dp[ind][f]=max(take,nottake);
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //dp[prices.size()][0]=0;
        //dp[prices.size()][0]=-1e9;
        for(int i=n-1;i>=0;i--)
        {
            for(int f=0;f<2;f++)
            {
                if(f==1)
                {
                    dp[i][f]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    dp[i][f]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
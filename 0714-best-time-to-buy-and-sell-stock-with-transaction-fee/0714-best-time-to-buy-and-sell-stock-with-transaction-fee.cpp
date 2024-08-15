class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        //vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>prev(2),next(2);
        for(int i=n-1;i>=0;i--)
        {
            for(int f=0;f<2;f++)
            {
                if(f==1)
                {
                    next[f]=max(-prices[i]+prev[0],prev[1]);
                }
                else
                {
                    next[f]=max(prices[i]-fee+prev[1],prev[0]);
                }
            }
            prev=next;
        }
        return prev[1];
    }
};
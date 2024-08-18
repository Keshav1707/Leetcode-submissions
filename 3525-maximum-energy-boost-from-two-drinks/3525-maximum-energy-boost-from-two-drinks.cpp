class Solution {
public:
long long dp[100009][2];
long long rec(int ind,vector<int>&a,vector<int>&b,bool f)
{
    if(ind>=a.size())return 0;
    if(dp[ind][f]!=-1)return dp[ind][f];
    long long sch=rec(ind+1,a,b,!f);
    long long take=0;
    if(f==0)take=a[ind]+rec(ind+1,a,b,f);
    else take=b[ind]+rec(ind+1,a,b,f);
    return dp[ind][f]=max(take,sch);

}
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        memset(dp,-1,sizeof(dp));
       long long a=rec(0,energyDrinkA,energyDrinkB,0); 
       long long b=rec(0,energyDrinkA,energyDrinkB,1);
       return max(a,b); 
    }
};
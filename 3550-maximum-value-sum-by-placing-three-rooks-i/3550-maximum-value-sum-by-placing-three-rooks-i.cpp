class Solution {
public:
    long long dp[101][102][102][3];
    long long rec(int ind,int preva,int prevb,int k,vector<vector<pair<int,int>>>&nums){
        if(ind>=nums.size()||k>=3){
            return k==3?0:-1e18;
        }
        if(dp[ind][preva+1][prevb+1][k]!=-1) return dp[ind][preva+1][prevb+1][k];
        long long ans=-1e18;
        for(int i=0;i<nums[ind].size();i++){
            for(auto &it:nums[ind]){
                if(ind==0||(it.second!=preva&&it.second!=prevb)){
                    ans=max(ans,1ll*it.first+rec(ind+1,it.second,preva,k+1,nums));
                }
            }
        }
        ans=max(ans,rec(ind+1,preva,prevb,k,nums));
        return dp[ind][preva+1][prevb+1][k] =ans;
    }
    long long maximumValueSum(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<pair<int,int>>>nums(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<board[0].size();j++){
                nums[i].push_back({board[i][j],j});
            }
            sort(nums[i].rbegin(),nums[i].rend());
            while(nums[i].size()>3){
                nums[i].pop_back();
            }
        }
        return rec(0,-1,-1,0,nums);
    }
};
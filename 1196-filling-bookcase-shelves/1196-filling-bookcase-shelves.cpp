class Solution {
public:
int dp[1009][1009];
int rec(int ind,int ht,int curwid,vector<vector<int>>& books, int shelfWidth)
{
    if(ind==books.size())return ht;
    if(dp[ind][curwid]!=-1)return dp[ind][curwid];
    int sameshelf=1e9,nextshelf=1e9;
    if(shelfWidth>=curwid+books[ind][0])
    {
        sameshelf=rec(ind+1,max(ht,books[ind][1]),curwid+books[ind][0],books,shelfWidth);
    }
    nextshelf=ht+rec(ind+1,books[ind][1],books[ind][0],books,shelfWidth);
    return dp[ind][curwid]=min(sameshelf,nextshelf);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,books,shelfWidth);
    }
};
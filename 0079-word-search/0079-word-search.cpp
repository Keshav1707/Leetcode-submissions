class Solution {
public:
bool rec(int i,int j,vector<vector<char>>& board,string s,int ind)
{
    if(ind==s.size())return true;
    if(i<0||j<0||i==board.size()||j==board[0].size()||board[i][j]!=s[ind]||board[i][j]=='!')return false;
    char c=board[i][j];
    board[i][j]='!';
    bool up=rec(i-1,j,board,s,ind+1);
    bool down=rec(i+1,j,board,s,ind+1);
    bool left=rec(i,j-1,board,s,ind+1);
    bool right=rec(i,j+1,board,s,ind+1);
    board[i][j]=c;
    return up||down||left||right;
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(rec(i,j,board,word,0))return true;
                }
            }
        }
        return false;
    }
};
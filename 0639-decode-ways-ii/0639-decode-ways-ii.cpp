
class Solution {
public:
    int dp[100009];
    const int MOD=1e9+7;
    bool isPossible(string& s) {
        if (s[0] == '0') return false;
        int num = stoi(s);
        return num >= 1 && num <= 26;
    }

    long long rec(int ind,string& s) {
        if (ind == s.size()) return 1;
        if (dp[ind] != -1) return dp[ind];
        long long count = 0;
        if (s[ind] == '*') 
        {
            count += (9%MOD * rec(ind + 1, s)%MOD)%MOD;
            if (ind + 1 < s.size()) 
                {
                    if (s[ind + 1] == '*') 
                    {
                            count +=15* rec(ind + 2, s)%MOD;
                    }
                    else if (s[ind + 1] == '0')
                {
                    count += 2 * rec(ind + 2, s);
                } 
                else {
                    for (int j = 1; j <= 9; ++j) {
                        string temp = to_string(j) + s[ind + 1];
                        if (isPossible(temp)) count += rec(ind + 2, s)%MOD;
                    }
                }
                } 
                
            }
        
        if(s[ind]!='*') 
        {
            if (s[ind] == '0') return 0;
            count += rec(ind + 1, s)%MOD;
            if (ind + 1 < s.size()) {
                if (s[ind + 1] == '*') {
                    for (int j = 1; j <= 9; ++j) {
                        string temp = s.substr(ind, 1) + to_string(j);
                        if (isPossible(temp)) count += rec(ind + 2, s)%MOD;
                    }
                } else {
                    string temp = s.substr(ind, 2);
                    if (isPossible(temp)) count += rec(ind + 2, s)%MOD;
                }
            }
        }
        return dp[ind] = count%MOD;
    }

    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
};

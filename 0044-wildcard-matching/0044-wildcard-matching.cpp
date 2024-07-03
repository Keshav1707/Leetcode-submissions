class Solution {
public:
    bool rec(int inda, int indb, string &s, string &p, vector<vector<int>> &dp) {
        if (dp[inda][indb] != -1) return dp[inda][indb];
        
        if (inda == s.size() && indb == p.size()) return dp[inda][indb] = true;
        
        if (indb == p.size() && inda < s.size()) return dp[inda][indb] = false;
        
        if (inda == s.size()) {
            for (int i = indb; i < p.size(); i++) {
                if (p[i] != '*') return dp[inda][indb] = false;
            }
            return dp[inda][indb] = true;
        }
        
        if (s[inda] == p[indb] || p[indb] == '?') {
            return dp[inda][indb] = rec(inda + 1, indb + 1, s, p, dp);
        } 
        
        if (p[indb] == '*') {
            return dp[inda][indb] = rec(inda + 1, indb, s, p, dp) || rec(inda, indb + 1, s, p, dp);
        }
        
        return dp[inda][indb] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return rec(0, 0, s, p, dp);
    }
};

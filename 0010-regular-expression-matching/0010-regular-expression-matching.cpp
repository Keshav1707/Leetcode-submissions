class Solution {
public:
    vector<vector<int>> dp;
    
    bool rec(int inda, int indb, string& s, string& p) {
        if (inda >= s.size() && indb >= p.size()) return true;
        if (indb >= p.size()) return false;  

        if (dp[inda][indb] != -1) return dp[inda][indb];

        bool a = (inda < s.size() && (s[inda] == p[indb] || p[indb] == '.'));;

        if (indb + 1 < p.size() && p[indb + 1] == '*')
        {
            dp[inda][indb] = (rec(inda, indb + 2, s, p) ||(a && rec(inda + 1, indb, s, p)));
        } 
        else
        {   
            dp[inda][indb] = a && rec(inda + 1, indb + 1, s, p);;
        }

        return dp[inda][indb];
    }
    
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return rec(0, 0, s, p);
    }
};

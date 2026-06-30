class Solution {
public:
    int numberOfSubstrings(string s) {
        int ct = 0;
        int lo = 0;
        map<char, int> m;
        
        for (int hi = 0; hi < s.size(); ++hi) {
            m[s[hi]]++;
            
            while (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {
                ct += s.length() - hi;
                m[s[lo]]--;
                lo++;
            }
        }
        
        return ct;
    }
};
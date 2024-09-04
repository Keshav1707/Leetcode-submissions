class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        
        set<pair<int, int>> s;
        for (auto i : obstacles) {
            s.insert({i[0], i[1]});
        }
        
        int ind = 0;
        int maxi = 0;
        
        for (auto c : commands) {
            if (c == -1) {
                ind = (ind + 1) % 4;
            } else if (c == -2) {
                ind = (ind + 3) % 4;
            } else {
                for (int i = 1; i <= c; i++) {
                    if (ind == 0) {
                        if (s.find({x, y + 1}) != s.end()) break;
                        else y++;
                    } else if (ind == 1) {
                        if (s.find({x + 1, y}) != s.end()) break;
                        else x++;
                    } else if (ind == 2) {
                        if (s.find({x, y - 1}) != s.end()) break;
                        else y--;
                    } else if (ind == 3) {
                        if (s.find({x - 1, y}) != s.end()) break;
                        else x--;
                    }
                }
                maxi = max(maxi, x * x + y * y);
            }
        }
        return maxi;
    }
};

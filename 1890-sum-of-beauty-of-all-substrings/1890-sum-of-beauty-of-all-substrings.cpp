class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            
            vector<int>v(26);
            for(int j=i;j<s.size();j++)
            {
                v[s[j]-'a']++;
                int maxi=0,mini=1e9;
                for (int k = 0; k < 26; k++) {
                    if (v[k] > 0) {
                        maxi = max(maxi, v[k]);
                        mini = min(mini, v[k]);
                    }
                }
                ans+=maxi-mini;
            }  
        }
        return ans;
    }
};
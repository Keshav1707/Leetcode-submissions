class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[1000]={0};
        int maxi=0;
        int strt=0;
        for(int i=0;i<s.size();i++)
        {
            a[s[i]]++;
            while(a[s[i]]>1)
            {
                a[s[strt]]--;
                strt++;
            }
            maxi=max(maxi,i-strt+1);
        }
        
        return maxi;
    }
};
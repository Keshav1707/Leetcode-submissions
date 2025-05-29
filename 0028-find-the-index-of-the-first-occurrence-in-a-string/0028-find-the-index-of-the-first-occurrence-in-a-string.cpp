class Solution {
public:
vector<int> lps(string s)
{
    int n=s.size();
    vector<int>pi(n);
    int j=0;
    for(int i=1;i<n;i++)
    {
        j=pi[i-1];
        while(j>0&&s[i]!=s[j])
        {
            j=pi[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        pi[i]=j;
    }
    return pi;
}
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>pi=lps(needle);
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(j>0&&haystack[i]!=needle[j])
            {
                j=pi[j-1];
            }
            if(haystack[i]==needle[j])
            {
                j++;
            }
            if(j==m)return i-m+1;
        }
        return -1;
    }
};
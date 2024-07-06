class Solution {
public:
    string maximumBinaryString(string s) {
        bool flag=0;
        int n=s.size();
        int prev;
        for(int i=0;i<n;i++)
        {
            if(!flag&&s[i]=='0')
            {
                flag=1;
                prev=i;
            }
            else if(s[i]=='0'&&flag)
            {
                swap(s[i],s[prev+1]);
                prev=prev+1;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0'&&s[i-1]=='0')
            {
                s[i-1]='1';
            }
        }
        return s;
    }
};
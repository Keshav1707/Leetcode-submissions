class Solution {
public:
bool fun(string s,int a,int b)
{
    while(a<b)
    {
        if(s[a]!=s[b])return false;
        a++;
        b--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else 
            {
                return fun(s,i+1,j)||fun(s,i,j-1);
            }
        }
        return 1;
    }
};
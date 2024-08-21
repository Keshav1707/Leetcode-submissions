class Solution {
public:
string rec(int n)
{
    if(n==1)return "1";

    string s=rec(n-1);
    string temp="";
    char c=s[0];
    int cnt=0;
    for(auto i : s)
    {
        if(i==c)cnt++;
        if(i!=c)
        {
            temp += to_string(cnt) + c;
                c=i;
                cnt=1;
        }
    }
    temp += to_string(cnt) + c;

        return temp;
}
    string countAndSay(int n) {
        return rec(n);
    }
};
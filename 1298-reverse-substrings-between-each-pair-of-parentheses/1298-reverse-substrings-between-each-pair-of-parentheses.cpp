class Solution {
public:
    string reverseParentheses(string s) {
        int a=0,b=s.size();
        stack<int>st;
        for(int i=0;i<b;i++)
        {
            if(s[i]=='(')st.push(i);
            else if(s[i]==')')
            {
                reverse(s.begin()+st.top()+1,s.begin()+i);
                st.pop();
            }
        }
        string temp="";
        for(auto i : s)
        {
            if(i=='('||i==')')continue;
            temp+=i;
        }
        return temp;
    }
};
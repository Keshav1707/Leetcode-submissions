class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i : s)
        {
            
            if(st.empty())
            {
                st.push(i);
            }
            
            else if(i==')'&&st.top()=='(')st.pop();
            else if(i==']'&&st.top()=='[')st.pop();
            else if(i=='}'&&st.top()=='{')st.pop();
            else st.push(i);
        }
        cout<<st.size();
        if(st.size()==0)
        return 1;
        return 0;
    }
};
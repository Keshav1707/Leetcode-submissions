class Solution {
public:
    int minimumDeletions(string s) {
       stack<char>st;
       int a=0;
       for(auto i : s)
       {
            if(!st.empty()&&st.top()=='b'&&i=='a')
            {
                st.pop();
                a++;
            }else
            st.push(i);
       } 
       return a;
    }
};
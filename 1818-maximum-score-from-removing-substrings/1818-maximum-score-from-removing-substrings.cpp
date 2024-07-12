class Solution {
public:
    int maximumGain(string s, int x, int y) {
        bool f=0;
        if(x<y)f=1;
        if(f==0)
        {
            int ans=0;
            stack<char>st;
            for(auto i : s)
            {
                if(st.empty())st.push(i);
                else if(st.top()=='a'&&i=='b')ans+=x,st.pop();
                else st.push(i);

            }
            s="";
            while(!st.empty())
            {
                s+=st.top();
                st.pop();
            }
            for(auto i : s)
            {
                if(st.empty())st.push(i);
                else if(st.top()=='a'&&i=='b')ans+=y,st.pop();
                else st.push(i);
            }
            return ans;
        }
        else
        {
            int ans=0;
            stack<char>st;
            for(auto i : s)
            {
                if(st.empty())st.push(i);
                else if(st.top()=='b'&&i=='a')ans+=y,st.pop();
                else st.push(i);
            }
            s="";
            while(!st.empty())
            {
                s+=st.top();
                st.pop();
            }
            for(auto i : s)
            {
                if(st.empty())st.push(i);
                else if(st.top()=='b'&&i=='a')ans+=x,st.pop();
                else st.push(i);
            }
            return ans;
        }
        return 0;
    }
};
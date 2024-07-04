class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>>mp;
        int a=0;
        for(auto i : s)
        {
            if(i=='*')
            {
                int ind=(*mp.begin()).second.back();
                (*mp.begin()).second.pop_back();
                if((*mp.begin()).second.size()==0)mp.erase(mp.begin());
                s[ind]='1';
            }
            else mp[i].push_back(a);
            a++;
        }
        string temp="";
        for(auto i : s)
        {
            if(i!='*'&&i!='1')temp+=i;
        }
        return temp;
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int a=0;
        for(auto i : details)
        {
            if((i[11]=='6'&&i[12]>'0')||i[11]>'6')a++;
        }
        return a;
    }
};
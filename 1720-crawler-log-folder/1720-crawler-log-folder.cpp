class Solution {
public:
    int minOperations(vector<string>& logs) {
        int a=0;
        for(auto i : logs)
        {
            if(i=="./")continue;
            else if(i=="../"&&a>0)a--;
            else if(i[0]!='.')a++;
        }
        return a;
    }
};
class Solution {
public:
int rec(int ind,vector<string>&words,vector<pair<int,int>>v)
{
    if(ind==words.size())
    {
        return 0;
    }
    int take=0,nottake=0;
    nottake=rec(ind+1,words,v);
    vector<pair<int,int>>h=v;
    int a=0;
    for(auto i : words[ind])
    {
        if(h[i-'a'].first>0)
        {
            a+=h[i-'a'].second;
            h[i-'a'].first--;
        }
        else
        {
            return nottake;
        }
    }
    take=a+rec(ind+1,words,h);
    return max(take,nottake);
}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<pair<int,int>>v;
        for(auto i : score)
        {
            v.push_back({0,i});
        }
        for(auto i : letters)
        {
            v[i-'a'].first++;
        }
        return rec(0,words,v);
    }
};
class Solution {
public:
    struct compare{
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first==b.first)
                return a.second > b.second;
            return a.first<b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(auto i : words)
        {
            m[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        for(auto i : m)
        {
            pq.push({i.second,i.first});
        }
        vector<string>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<int>pqa;
        for(int i=0;i<capital.size();i++)
        {
            pq.push({capital[i],profits[i]});
        }
        for(int i=0;i<k;i++)
        {
            while(!pq.empty()&&pq.top().first<=w)
            {
                pqa.push(pq.top().second);
                pq.pop();
            }
            if(pqa.empty())break;
            w+=pqa.top();
            pqa.pop();
        }
        return w;
    }
};
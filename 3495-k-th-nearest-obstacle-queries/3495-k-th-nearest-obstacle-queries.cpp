class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
       priority_queue<int>pq;
       vector<int>ans;
       for(auto i : queries)
       {
            pq.push({abs(i[0])+abs(i[1])});
            if(pq.size()>k)pq.pop();
            if(pq.size()==k)
            {
                ans.push_back(pq.top());
            }
            else ans.push_back(-1);
       } 
       return ans;
    }
};
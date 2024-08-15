class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto i : piles)pq.push(i);
        while(k--)
        {
            int n=pq.top();
            pq.pop();
            n=(n+1)/2;
            pq.push(n);
        }
        int sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
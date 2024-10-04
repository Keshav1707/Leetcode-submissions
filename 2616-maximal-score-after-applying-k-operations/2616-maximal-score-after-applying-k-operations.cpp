class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
       priority_queue<int>pq(nums.begin(),nums.end());
       long long sum=0;
       while(k--)
       {
            sum+=pq.top();
            int x=(pq.top()/3);
            if(pq.top()%3)x++;
            pq.pop();
            pq.push(x);
       } 
       return sum;
    }
};
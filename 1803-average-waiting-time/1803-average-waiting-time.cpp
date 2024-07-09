class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      int curtime=0;
      double sum=0;
      for(auto i : customers)
      {
        curtime=max(curtime+i[1],i[0]+i[1]);
        sum+=curtime-i[0];
      }  
        double avg=sum/customers.size();
        return avg;
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
      int curtime=customers[0][0];
      double sum=0;
      for(auto i : customers)
      {
        curtime=max(curtime+i[1],i[0]+i[1]);
        sum+=abs(curtime-i[0]);
      }  
        double avg=sum/customers.size();
        return avg;
    }
};
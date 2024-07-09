class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      int curtime=0;
      double sum=0;
      int n=customers.size();
      for(int i=0;i<n;i++)
      {
        if(curtime>customers[i][0])
        {
            curtime=curtime+customers[i][1];
        }
        else
        {
            curtime=customers[i][0]+customers[i][1];
        }
        
        sum+=curtime-customers[i][0];
      }  
        
        return sum/n;
    }
};
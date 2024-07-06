class Solution {
public:
    int passThePillow(int n, int time) {
      int i=1;
      bool flag=1;
      while(time--)
      {
            if(i==n)flag=0;
            if(i==1)flag=1;
            if(flag)i++;
            else i--;
      }  
      return i;
    }
};
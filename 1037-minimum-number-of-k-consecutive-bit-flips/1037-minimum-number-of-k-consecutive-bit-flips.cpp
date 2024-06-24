class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
      int a=0,f=0;
      for(int i=0;i<nums.size();i++)
      {
        if((nums[i]+a)%2==0)
        {
            if(i>nums.size()-k)
            {
                return -1;


            }
                a++;
                f++;
                nums[i]=-1;
        }
        if(i+1>=k)
        {
            a-=(nums[i-k+1]<0);
        }
      }
      return f;  
    }
};
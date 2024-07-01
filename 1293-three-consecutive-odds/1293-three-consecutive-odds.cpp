class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       
       int a=0;
       for(auto i : arr)
       {
            
            if((i&1)==1)a++;
            else a=0;
            if(a==3)return 1;
       } 
       return 0;
    }
};
class Solution {
public:
    int longestMountain(vector<int>& arr) {
       vector<int>lisleft(arr.size(),0),lisright(arr.size(),0);
       for(int i=1;i<arr.size();i++)
       {
            if(arr[i]>arr[i-1])lisleft[i]=1+lisleft[i-1];
       }
       for(int i=arr.size()-2;i>=0;i--)
       {
            if(arr[i]>arr[i+1])lisright[i]=1+lisright[i+1];
       } 
       int maxi=0;
       for(int i=0;i<arr.size();i++)
       {
        if(lisleft[i]!=0&&lisright[i]!=0)
        {
            maxi=max(maxi,1+lisleft[i]+lisright[i]);
        }
       }
       return maxi;
    }
};
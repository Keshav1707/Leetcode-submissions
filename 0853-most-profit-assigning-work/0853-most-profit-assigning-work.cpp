class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
     vector<pair<int,int>>v(profit.size());
     for(int i=0;i<profit.size();i++)
     {
        v[i]={difficulty[i],profit[i]};
     } 
     sort(v.begin(),v.end());
     vector<int>mx;
     int maxi=0;
     for(int i=0;i<v.size();i++)
     {
        maxi=max(maxi,v[i].second);
        mx.push_back(maxi);
     }
     int ultans=0;  
     for(auto cap : worker)
     {
        int beg=0,end=v.size()-1;
        int mid;
        int ans;
        while(beg<=end)
        {
            mid=(beg+end)>>1;
            if(v[mid].first>cap)end=mid-1;
            else
            {
                ans=v[mid].second;
                beg=mid+1;
            }
        }
        if(end>=0)
        ultans+=mx[end];
     }
     return ultans;
    }
};
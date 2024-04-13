class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxi=0;
        vector<pair<int,int>>v(n,{0,0});
        for(int i=n-1;i>=0;i--)
        {
            v[i].first=maxi;
            maxi=max(maxi,height[i]);
        }
        
        maxi=0;
        for(int i=0;i<n;i++)
        {
            v[i].second=maxi;
            maxi=max(maxi,height[i]);
        }
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            //cout<<min(v[i].first,v[i].second)-height[i]<<endl;
            cout<<v[i].first<<" "<<v[i].second<<endl;
            sum+=max(0,min(v[i].first,v[i].second)-height[i]);
        }
        return sum;
    }
};
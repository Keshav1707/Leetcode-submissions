class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int maxi=0;
        if(points.size()<=2)return points.size();
        for(int i=0;i<points.size()-1;i++)
        {
            map<double,int>m;
            int maxia=0;
            for(int j=i+1;j<points.size();j++)
            {
                int a=points[i][1]-points[j][1];
                int b=points[i][0]-points[j][0];
                if(a==0&&b==0)continue;
                double slope=0;
                if(b==0)slope=INT_MAX,m[slope]++;
                else{
                slope=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                m[slope]++;}
                maxia=max(maxia,m[slope]);
                
            }
            maxi=max(maxia,maxi);
        }
        cout<<maxi+1<<endl;
        //int x=(1+sqrt(1-4*1*(-maxi*2)))/2;
        
        return maxi+1;
    }
};
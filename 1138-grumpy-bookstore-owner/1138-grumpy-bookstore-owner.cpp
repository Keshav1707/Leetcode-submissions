class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)sum+=customers[i];
        }
        int maxi=0;
        int sumn=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)sumn+=customers[i];
        }
        int beg=0,end=minutes;
        maxi=sumn;
        while(end<grumpy.size())
        {
            if(grumpy[beg]==1)sumn-=customers[beg];
            if(grumpy[end]==1)sumn+=customers[end];
            beg++,end++;
            maxi=max(maxi,sumn);
        }
        cout<<sum<<" "<<maxi<<endl;
        return sum+maxi;
    }
};
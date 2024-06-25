class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            bool f=0;
            int a=0;
            for(int j=i+1;j<arr.size();j++)
            {
                if(j==i+1)if(arr[j-1]>arr[j])f=1;
                if(f&&arr[j-1]>arr[j])
                {
                    a++;
                    f=0;
                }
                else if(!f&&arr[j-1]<arr[j])
                {
                    f=1;
                    a++;
                }
                else break;
            }
            maxi=max(maxi,a);
        }
        return maxi+1;
    }
};
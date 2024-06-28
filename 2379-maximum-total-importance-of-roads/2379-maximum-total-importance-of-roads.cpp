class Solution {
public:
 
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       map<long long,long long>m;
       for(auto i : roads)
       {
            
            m[i[0]]++;
            m[i[1]]++;
        
       }
       vector<long long>v;
        for(auto i : m)
        {
            
            v.push_back(i.second);
        }
        sort(v.rbegin(),v.rend());
        long long sum=0;
        for(long long i=0;i<v.size();i++)
        {
            sum+=v[i]*(n);
            n--;
        }
        return sum;
    }
};
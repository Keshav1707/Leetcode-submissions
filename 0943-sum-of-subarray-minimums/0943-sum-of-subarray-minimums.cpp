const int MOD=1e9+7;
using ll = long long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int>s;
        int n=arr.size();
        vector<int>right(n,n),left(n,-1);
        for(int i=0;i<n;++i)
        {
            while(!s.empty()&&arr[s.top()]>=arr[i])s.pop();
            if(!s.empty())left[i]=s.top();
            s.push(i);
        }
        s=stack<int>();
        for(int i=n-1;i>=0;--i)
        {
            while(!s.empty()&&arr[s.top()]>arr[i])s.pop();
            if(!s.empty())right[i]=s.top();
            s.push(i);
        }
        ll sum=0;
        for(int i=0;i<n;++i)
        {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }
        return sum;
    }
};
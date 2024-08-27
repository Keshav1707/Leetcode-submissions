class Solution {
public:
 bool fun(vector<int>& jobs,vector<int>sum, int mid,int ind,int k) {
        if(ind == jobs.size()) return true;
        
        for(int i = 0; i < k; i++) {
            if(sum[i] + jobs[ind] <= mid) {
                sum[i] += jobs[ind];
                if(fun(jobs, sum, mid, ind+1,k)) return true;
                sum[i] -= jobs[ind];
            }
            if(sum[i] == 0) break;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end());
        int lo=*max_element(jobs.begin(), jobs.end()),hi=accumulate(jobs.begin(),jobs.end(),0);
        int mid;
        while(lo<hi)
        {
            mid=(lo+hi)>>1;
            vector<int>sum(k);
            if(fun(jobs,sum,mid,0, k))hi=mid;
            else lo=mid+1;
        }
        return hi;
    }
};
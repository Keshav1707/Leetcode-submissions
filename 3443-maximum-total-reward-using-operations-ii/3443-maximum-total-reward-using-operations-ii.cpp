class Solution {
public:
    
    int maxTotalReward(vector<int>& v) {
        sort(v.begin(),v.end());
        bitset<100005>sums,mask,validprev;
        sums[0]=1;
        int maskind=0;
        for(auto i : v)
        {
            while(maskind<i)mask[maskind]=1,maskind++;
            validprev=sums&mask;
            sums=sums|(validprev<<i);
        }
        maskind=1e5;
        while(sums[maskind]==0)maskind--;
        return maskind;
    }
};
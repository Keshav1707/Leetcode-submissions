class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int a=0;
       vector<int>zeros;
        zeros.push_back(0);
        map<int,vector<int>>m;
        m[0].push_back(-1);
       for(int i=0;i<nums.size();i++)
       {
            if(nums[i]==0)a-=1;
            else a++;
            m[a].push_back(i);
            //zeros.push_back(a);
       } 
       int maxi=0;
       for(auto i : m)
       {
            maxi=max(i.second.back()-i.second[0],maxi);
       }
       return maxi;
    }
};
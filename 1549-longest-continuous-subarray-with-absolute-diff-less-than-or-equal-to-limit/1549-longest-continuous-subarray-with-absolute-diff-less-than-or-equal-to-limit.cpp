class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       multiset<int>s;
       int beg=0,end=0; 
       int maxi=0;
       while(end<nums.size())
       {
            s.insert(nums[end]);
            while((*s.rbegin()-*s.begin())>limit)
            {
                //cout<<*nums.end()-*nums.begin()<<endl;
                s.erase(s.find(nums[beg]));
                beg++;
            }
            maxi=max(maxi,end-beg+1);
            end++;
       }
       return maxi;
    }
};

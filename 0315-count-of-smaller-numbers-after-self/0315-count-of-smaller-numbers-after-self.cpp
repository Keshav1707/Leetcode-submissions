
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


      typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>set_t;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        set_t s;
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            s.insert(nums[i]);
            ans.push_back(s.order_of_key(nums[i]));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
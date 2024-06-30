class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int far=0;
        int curfar=0;
        int jump=0;
        for(int i=0;i<nums.size();i++)
        {
            far=max(far,i+nums[i]);
            if(i==curfar)
            {
                jump++;
                curfar=far;
                if(curfar>=nums.size()-1)break;
            }
        }
        return jump;
    }
};
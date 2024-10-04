class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long sum=skill[0]+skill.back();
        long long pro=0;
        for(int i=0;i<skill.size()/2;i++)
        {
            if(sum!=skill[i]+skill[skill.size()-i-1])return -1;
            else pro+=skill[i]*(skill[skill.size()-i-1]);
        }
        return pro;
    }
};
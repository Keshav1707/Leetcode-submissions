class Solution {
public:
    long long countVowels(string word) {
        vector<long long>x;
        long long ind=0;
        long long n=word.size();
        long long ans=0;
        long long vow=0;
        for(auto i : word)
        {
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')
            {
                ans+=(n-ind)*(ind+1);
            }
            ind++;
        }
        
        
        return ans;
    }
};
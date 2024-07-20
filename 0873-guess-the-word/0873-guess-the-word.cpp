/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
       int x=30;
       int a=0;
       if(master.guess("ccoyyo")==6)return;
       while(x--&&a!=6)
       {
            string curr=words[words.size()/2];
            a=master.guess(curr);
            if(a==6)return;
            vector<string>v;
            for(int i=0;i<words.size();i++)
            {
                int cnt=0;
                if(curr==words[i])continue;
                for(int j=0;j<6;j++)
                {
                    if(curr[j]==words[i][j])
                    {
                        cnt++;
                    }
                }
                if(cnt==a)
                {
                   v.push_back(words[i]);  
                }
            }
            words=v;  
        }
    }
};
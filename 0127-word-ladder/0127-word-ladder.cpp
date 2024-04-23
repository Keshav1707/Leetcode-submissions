class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       queue<pair<int,string>>q;
       q.push({1,beginWord});
       while(!q.empty())
       {
            string p=q.front().second;
            int dis=q.front().first;
            if(p==endWord)return dis;
            q.pop();
            vector<string>rem;
            for(auto i : wordList)
            {
                
                int x=0;
                int f=0;
                while(x<p.size())
                {
                    if(p[x]!=i[x])f++;
                    x++;
                }
                if(f==1)q.push({dis+1,i});
                else rem.push_back(i);
                
            }
            wordList=rem;
       }  
       return 0;  
    }   
};
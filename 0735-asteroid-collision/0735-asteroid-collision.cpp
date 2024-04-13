class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int>s;
       
       for(int i=0;i<asteroids.size();i++)
       {
            if(s.empty()||asteroids[i]>0)s.push(asteroids[i]);
            else
            {
            while(!s.empty()&&s.top()>0&&abs(asteroids[i])>s.top())
            {
                s.pop();
            }
            if(!s.empty()&&s.top()>0&&abs(asteroids[i])==s.top())s.pop();
            else if(s.empty()||s.top()<0)
            {
                s.push(asteroids[i]);
            }
            }
            

       } 
       vector<int>v;
       while(!s.empty())
       {
        v.push_back(s.top());
        s.pop();
       }
       reverse(v.begin(),v.end());
       return v;
    }
};
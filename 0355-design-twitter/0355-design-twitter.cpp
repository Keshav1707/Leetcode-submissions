class Twitter {
public:
unordered_map<int,unordered_set<int>>m;
unordered_map<int,priority_queue<pair<int,int>>>pq;
int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq[userId].push({time,tweetId});
        time++;
    }
    vector<int> getNewsFeed(int userId) {
        m[userId].insert(userId);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
        for(auto i : m[userId])
        {
            priority_queue<pair<int,int>>t2;
            while(!pq[i].empty())
            {
                temp.push(pq[i].top());
                t2.push(pq[i].top());
                pq[i].pop();
                if(temp.size()>10)temp.pop();
            }
            pq[i]=t2;
        }
        vector<int>ans;
        while(!temp.empty())
        {
            ans.push_back(temp.top().second);
            temp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
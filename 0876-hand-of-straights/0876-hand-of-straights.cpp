class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         priority_queue<int ,vector<int>,greater<int>> pq;
         for(auto i:hand)pq.push(i);
         int i=0;
         
         while(i<hand.size())
         {
            int prev=pq.top();
            pq.pop();
            int temp=1;
            vector<int>v;
            while(!pq.empty()&&temp<groupSize)
            {
                if(pq.top()==prev+1)
                {
                    temp++;
                    prev=pq.top();
                    //cout<<prev<<" ";
                    pq.pop();

                }
                else if(pq.top()==prev)
                {
                    v.push_back(pq.top());
                    pq.pop();
                }
                else return false;
            }
            cout<<endl;
            cout<<temp<<endl;
            if(temp!=groupSize)return false;
            for( auto i:v)pq.push(i);
            i+=temp;
         }
         return true;
    }
};
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int x=(minutesToTest/minutesToDie)+1;
        int p=0;
        while(pow(x,p)<buckets)
        {
            p++;
        }
        return p;
    }
};
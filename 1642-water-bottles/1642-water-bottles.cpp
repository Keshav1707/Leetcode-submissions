class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int a=0;
        int rem=0;
        while(numBottles)
        {
            a+=numBottles;
            int x=(numBottles+rem)/numExchange;
            rem=(numBottles+rem)%numExchange;
            numBottles=x;
        }
        return a;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) {
    
    int beg=0;
    int cursum=0;
    int totsum=0;
    for(int i=0;i<A.size();i++)
    {
        
        cursum+=A[i]-B[i];
        totsum+=A[i]-B[i];
        if(cursum<0)
        {
            beg=i+1;
            cursum=0;
        }
    }
    if(totsum<0)return -1;
    return beg;
    }
};
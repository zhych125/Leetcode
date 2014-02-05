class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n==0) {
            return 0;
        }
        int ones=0;
        int twos=0;
        int threes=0;
        for(int i=0;i<n;i++) {
            threes=twos&A[i];
            ones=ones^A[i];
            twos=twos|(ones&A[i]);
            ones=ones^threes;
            twos=twos^threes;
        }
        return ones;
    }
};
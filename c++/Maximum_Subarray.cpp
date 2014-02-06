class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) {
            return 0;
        }
        int sum=A[0];
        int curSum=0;
        bool posFlag=false;
        for(int i=0;i<n;i++) {
            if(!posFlag) {
                if(A[i]>sum) {
                    sum=A[i];
                }
                if(A[i]>0) {
                    posFlag=true;
                    curSum=A[i];
                }
            }
            else {
                curSum+=A[i];
                sum=max(sum,curSum);
                if(curSum<0) {
                    curSum=0;
                }
            }
        }
        return sum;
    }
};
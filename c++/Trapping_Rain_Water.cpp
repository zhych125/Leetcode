class Solution {
public:
    int trap(int A[], int n) {
        if(n<=2) {
            return 0;
        }
        int maxLeft=A[0];
        vector<int> left(n,0);
        for (int i=1;i<n;i++) {
            if(A[i]>maxLeft) {
                maxLeft=A[i];
            }
            left[i]=maxLeft;
        }
        int maxRight=A[n-1];
        int sum=0;
        for(int i=n-2;i>=0;i--) {
            if(A[i]>maxRight) {
                maxRight=A[i];
            }
            int waterLevel=maxRight;
            if(left[i]<=maxRight) {
                waterLevel=left[i];
            }
            sum+=waterLevel-A[i]>0?waterLevel-A[i]:0;
        }
        return sum;
    }
};
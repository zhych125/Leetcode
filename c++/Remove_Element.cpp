class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0) {
            return 0;
        }
        n=n-1;
        int i=0;
        while(i<=n) {
            if(A[i]==elem) {
                int temp=A[i];
                A[i]=A[n];
                A[n]=temp;
                n--;
            }
            else {
                i++;
            }
        }
        return n+1;
    }
};
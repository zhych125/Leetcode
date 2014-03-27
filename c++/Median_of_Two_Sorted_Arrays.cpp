class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2) return findKelements(A,m,B,n,(m+n)/2+1);
        else return (findKelements(A,m,B,n,(m+n)/2)+findKelements(A,m,B,n,(m+n)/2+1))/2;
    }
    
    double findKelements(int A[],int m,int B[],int n, int k) {
        if(m>n) {
            return findKelements(B,n,A,m,k);
        }
        if(m==0) {
            return B[k-1];
        }
        if(k==1) {
            return min(A[0],B[0]);
        }
        int pa = min(k/2,m);
        int pb = k-pa;
        if(A[pa-1]<B[pb-1]) {
            return findKelements(A+pa,m-pa,B,n,k-pa);
        }
        else if(A[pa-1]>B[pb-1]){
            return findKelements(A,m,B+pb,n-pb,k-pb);
        }
        else return A[pa-1];
    }
};
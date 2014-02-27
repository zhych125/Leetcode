class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int cur=0;
        for(int i=0;i<n;i++) {
            if(A[i]!=elem) {
                A[cur]=A[i];
                cur++;
            }
        }
        return cur;
    }
};
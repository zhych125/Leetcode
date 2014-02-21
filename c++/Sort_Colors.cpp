class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=1) {
            return;
        }
        int red=0;
        int blue=n-1;
        while(A[red]==0) red++;
        while(A[blue]==2) blue--;
        int i=red;
        while(i<=blue) {
            if(A[i]==0) {
                swap(A,red,i);
                i++;
                red++;
            }
            else if(A[i]==2) {
                swap(A,blue,i);
                blue--;
            }
            else i++;
        }
    }
    void swap(int A[],int a,int b) {
        int tmp=A[a];
        A[a]=A[b];
        A[b]=tmp;
    }
};
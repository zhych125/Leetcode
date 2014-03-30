class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) 
            return 0;
        int repeat=1;
        int oldValue = A[0];
        int index = 1;
        for(int i=1;i<n;i++) {
           if(A[i] == oldValue) {
               if(repeat == 1) {
                   repeat++;
                   swap(A,index,i);
                   index++;
               }
           }
           else {
               oldValue = A[i];
               repeat = 1;
               swap(A,index,i);
               index++;
           }
        }
        return index;
    }
    void swap(int A[],int i,int j) {
        int temp = A[i];
        A[i]=A[j];
        A[j]=temp;
    }
};
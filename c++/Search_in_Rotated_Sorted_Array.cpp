class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==0) {
            return -1;
        }
        int begin=0;
        int end=n-1;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(A[mid]==target) {
                return mid;
            }
            if(A[mid]>=A[begin]) {
                if(A[mid]>target&&A[begin]<=target) {
                    end=mid-1;
                }
                else {
                    begin=mid+1;
                }
            }
            else if(A[mid]<A[begin]) {
                if(A[mid]<target&&A[end]>=target) {
                    begin=mid+1;
                }
                else {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
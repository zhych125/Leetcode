class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==0) {
            return 0;
        }
        int begin=0;
        int end=n-1;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(target==A[mid]) {
                return mid;
            }
            else if(target>A[mid]) {
                begin=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return begin;
    }
};
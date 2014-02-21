class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret={-1,-1};
        if(n<1) {
            return ret;
        }
        int begin=0;
        int end=n-1;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(A[mid]>=target) {
                end=mid-1;
            }
            else {
                begin=mid+1;
            }
        }
        if(A[begin]!=target) {
            return ret;
        }
        else {
            ret[0]=begin;
        }
        begin=0; end=n-1;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(A[mid]>target) {
                end=mid-1;
            }
            else {
                begin=mid+1;
            }
        }
        ret[1]=begin-1;
        return ret;
    }
};
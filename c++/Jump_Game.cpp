class Solution {
public:
    bool canJump(int A[], int n) {
        int begin=0;
        int end=0;
        while(begin<=end) {
            int e=end;
            for(int i=begin;i<=e;i++) {
                end=max(end,A[i]+i);
                if(end>=n-1) {
                    return true;
                }
            }
            begin=e+1;
        }
        return false;
    }
};
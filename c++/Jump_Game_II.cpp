class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1) {
            return 0;
        }
        int begin=0;
        int end=0;
        int step=0;
        while(begin<=end) {
            step++;
            int e=end;
            for(int i=begin;i<=e;i++) {
                end=max(end,A[i]+i);
                if(end>=n-1) {
                    return step;
                }
            }
            begin=e+1;
        }
        return -1;
    }
};
class Solution {
public:
    int sqrt(int x) {
        if(x==0) {
            return 0;
        }
        int begin = 1;
        int end = x/2+1;
        while(begin<=end) {
            long long mid = begin+(end-begin)/2;
            if(mid*mid==x) {
                return mid;
            } else if(mid*mid>x) {
                end=mid-1;
            } else {
                begin=mid+1;
            }
            
        }
        return end;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int de=abs((dividend));
        unsigned int di=abs((divisor));
        unsigned int ret=0;
        while(de>=di) {
            int res=1;
            unsigned int d=di;
            while(de-d>=d) {
                d<<=1;
                res<<=1;
            }
            ret+=res;
            de-=d;
        }
        return (dividend^divisor)>>31?-(int)ret:(int)ret;
    }
};
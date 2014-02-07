class Solution {
public:
    int atoi(const char *str) {
        while(*str==' ') {
            str++;
        }
        bool flag=true;
        if(*str=='+') {
            str++;
        }
        else if(*str=='-') {
            flag=false;
            str++;
        }
        int ret=0;
        while(*str<='9'&&*str>='0') {
            if(ret>INT_MAX/10||(ret==INT_MAX/10&&*str-'0'>7)) {
                return flag?INT_MAX:INT_MIN;
            }
            ret=ret*10+(*str)-'0';
            str++;
        }
        return flag?ret:-ret;
    }
};
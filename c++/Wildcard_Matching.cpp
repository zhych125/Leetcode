class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s==NULL||p==NULL) {
            return false;
        }
        int a=0,b=0;
        int star=-1;
        int strstar=-1;
        while(s[a]) {
            if(p[b]=='?'||s[a]==p[b]) {
                a++;
                b++;
            }
            else if(p[b]=='*') {
                star=b++;
                strstar=a;
            }
            else if(star>=0) {
                b=star+1;
                a=++strstar;
            }
            else return false;
        }
        while(p[b]=='*') b++;
        return !p[b];
    }
};